/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:36:25 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 12:37:07 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			sp_intersect2(t_ray *ray, t_sphere *sphere)
{
	double		b;
	double		c;
	t_vect		ray_sp_o;

	ray_sp_o = vect_diff(ray->origin, sphere->o);
	b = 2 * vect_dot(ray->dir, ray_sp_o);
	c = vect_dot(ray_sp_o, ray_sp_o) - sphere->r * sphere->r;
	return (solve_rt_quadratic(1, b, c));
}

double			pl_intersect2(t_ray *ray, t_plane *plane)
{
	double		dir_dot_n;
	t_vect		p_o;
	double		t;

	dir_dot_n = vect_dot(ray->dir, plane->n);
	if (fabs(dir_dot_n) > 10e-7)
	{
		p_o = vect_diff(plane->p, ray->origin);
		t = vect_dot(p_o, plane->n) / dir_dot_n;
		if (t >= 0)
			return (t);
	}
	return (-1);
}

double			sq_intersect2(t_ray *ray, t_square *sq)
{
	t_plane	plane;
	t_vect	hit;
	t_vect	origin_to_hit;
	double	t;

	plane.n = sq->normal;
	plane.p = sq->origin;
	if ((t = pl_intersect2(ray, &plane)) >= 0)
	{
		hit = vect_const_prod(t, ray->dir);
		hit = vect_sum(ray->origin, hit);
		origin_to_hit = vect_diff(hit, sq->origin);
		if (fabs(vect_dot(origin_to_hit, sq->u)) < sq->side / 2 &&
				fabs(vect_dot(origin_to_hit, sq->v)) < sq->side / 2)
			return (t);
	}
	return (-1);
}

double			cy_intersect2(t_ray *ray, t_cylinder *cy)
{
	t_coeff		equat;
	t_vect		oc_c;
	t_vect		tmp_vect;
	double		t;

	oc_c = vect_diff(cy->origin, ray->origin);
	equat.a = 1 - vect_dot(ray->dir, cy->axis) * vect_dot(ray->dir, cy->axis);
	equat.b = vect_dot(ray->dir, cy->axis) * vect_dot(oc_c, cy->axis);
	equat.b = equat.b - vect_dot(oc_c, ray->dir);
	equat.b = 2 * equat.b;
	tmp_vect = vect_diff(oc_c,
			vect_const_prod(vect_dot(oc_c, cy->axis), cy->axis));
	equat.c = vect_dot(tmp_vect, tmp_vect) - cy->radius * cy->radius;
	t = solve_rt_quadratic(equat.a, equat.b, equat.c);
	if (t < (vect_dot(cy->axis, oc_c) / vect_dot(ray->dir, cy->axis)) ||
			t > ((cy->height + vect_dot(cy->axis, oc_c))
				/ vect_dot(ray->dir, cy->axis)))
		return (-1);
	return (t);
}

double			tr_intersect2(t_ray *ray, t_triangle *tr)
{
	t_vect		hit;
	t_plane		plane;
	double		t;

	plane.n = vect_cross(vect_diff(tr->pt_b, tr->pt_a),
						vect_diff(tr->pt_c, tr->pt_a));
	plane.n = vect_unit(plane.n);
	tr->normal = plane.n;
	plane.p = tr->pt_a;
	if ((t = pl_intersect2(ray, &plane)) >= 0)
	{
		hit = vect_const_prod(t, ray->dir);
		hit = vect_sum(ray->origin, hit);
		if (vect_dot(plane.n, vect_cross(vect_diff(tr->pt_b, tr->pt_a),
										vect_diff(hit, tr->pt_a))) >= 0 &&
			vect_dot(plane.n, vect_cross(vect_diff(tr->pt_c, tr->pt_b),
										vect_diff(hit, tr->pt_b))) >= 0 &&
			vect_dot(plane.n, vect_cross(vect_diff(tr->pt_a, tr->pt_c),
										vect_diff(hit, tr->pt_c))) >= 0)
			return (t);
	}
	return (-1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:36:25 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 15:56:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			sp_intersect(t_ray *ray, t_sphere *sphere)
{
	t_coeff		coef;
	t_vect		ray_sp_o;
	double		t1;
	double		t2;
	double		delta;

	ray_sp_o = vect_diff(ray->origin, sphere->o);
	coef.b = 2 * vect_dot(ray->dir, ray_sp_o);
	coef.c = vect_dot(ray_sp_o, ray_sp_o) - sphere->r * sphere->r;
	delta = coef.b * coef.b - 4 * coef.c;
	if (delta < 0)
		return (-1);
	t1 = (-coef.b - sqrt(delta)) / 2;
	t2 = (-coef.b + sqrt(delta)) / 2;
	if (t1 < 0 && t2 < 0)
		return (-1);
	if ((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0))
		return (t1 > t2 ? t1 : t2);
	return (t1 < t2 ? t1 : t2);
}

double			pl_intersect(t_ray *ray, t_plane *plane)
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

double			sq_intersect(t_ray *ray, t_square *sq)
{
	t_plane	plane;
	t_vect	hit;
	t_vect	origin_to_hit;
	double	t;

	plane.n = sq->normal;
	plane.p = sq->origin;
	if ((t = pl_intersect(ray, &plane)) >= 0)
	{
		hit = vect_const_prod(t, ray->dir);
		hit = vect_sum(ray->origin, hit);
		sq->u = vect_cross(sq->normal, ray->cam_up);
		sq->v = vect_cross(sq->normal, sq->u);
		sq->u = vect_unit(sq->u);
		sq->v = vect_unit(sq->v);
		origin_to_hit = vect_diff(hit, sq->origin);
		if (fabs(vect_dot(origin_to_hit, sq->u)) < sq->side / 2 &&
				fabs(vect_dot(origin_to_hit, sq->v)) < sq->side / 2)
			return (t);
	}
	return (-1);
}

double			cy_intersect(t_ray *ray, t_cylinder *cy)
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
	t = limit_cylinder(&equat, ray, cy);
	return (t);
}

double			tr_intersect(t_ray *ray, t_triangle *tr)
{
	t_vect		hit;
	t_plane		plane;
	double		t;

	plane.n = vect_cross(vect_diff(tr->pt_b, tr->pt_a),
			vect_diff(tr->pt_c, tr->pt_a));
	plane.n = vect_unit(plane.n);
	tr->normal = plane.n;
	plane.p = tr->pt_a;
	if ((t = pl_intersect(ray, &plane)) >= 0)
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

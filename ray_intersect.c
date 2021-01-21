/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:09:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 18:48:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			set_hit_color(t_hit *hit)
{
	void		*obj;

	obj = hit->obj->content;
	if (hit->obj->element == rt_sphere)
		hit->color = ((t_sphere *)obj)->color_vect;
	else if (hit->obj->element == rt_cylinder)
		hit->color = ((t_cylinder *)obj)->color_vect;
	else if (hit->obj->element == rt_plane)
		hit->color = ((t_plane *)obj)->color_vect;
	else if (hit->obj->element == rt_square)
		hit->color = ((t_square *)obj)->color_vect;
	else if (hit->obj->element == rt_triangle)
		hit->color = ((t_triangle *)obj)->color_vect;
}

/*
** void				set_cy_normal(t_hit *hit, t_cylinder *cy)
** {
** 	hit->normal = vect_diff(hit->ray_obj, cy->origin);
** 	hit->normal = vect_diff(hit->normal,
** 		vect_const_prod(vect_dot(cy->axis, hit->normal), cy->axis));
** 	hit->normal = vect_unit(hit->normal);
** }
*/

void			set_planar_normals(t_vect og_norml, t_hit *hit)
{
	if (vect_dot(og_norml, hit->view) < 0)
		hit->normal = vect_const_prod(-1, og_norml);
	else
		hit->normal = og_norml;
}

void			set_hit(t_hit *hit, t_ray *ray)
{
	void		*obj;

	obj = hit->obj->content;
	hit->ray_obj = vect_const_prod(hit->t, ray->dir);
	hit->ray_obj = vect_sum(ray->origin, hit->ray_obj);
	hit->view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	set_hit_color(hit);
	if (hit->obj->element == rt_sphere)
		hit->normal = vect_unit(vect_diff(hit->ray_obj, ((t_sphere *)obj)->o));
	else if (hit->obj->element == rt_cylinder)
	{
		hit->normal = vect_diff(hit->ray_obj, ((t_cylinder *)obj)->origin);
		hit->normal = vect_unit(vect_diff(hit->normal,
			vect_const_prod(vect_dot(((t_cylinder *)obj)->axis, hit->normal),
			((t_cylinder *)obj)->axis)));
	}
	else if (hit->obj->element == rt_plane)
		set_planar_normals(((t_plane *)obj)->n, hit);
	else if (hit->obj->element == rt_square)
		set_planar_normals(((t_square *)obj)->normal, hit);
	else if (hit->obj->element == rt_triangle)
		set_planar_normals(((t_triangle *)obj)->normal, hit);
}

double			one_obj_intersect(t_ray *ray, t_list *obj_node)
{
	double		t;

	t = -1;
	if (obj_node->element == rt_sphere)
		t = sp_intersect(ray, obj_node->content);
	else if (obj_node->element == rt_cylinder)
		t = cy_intersect(ray, obj_node->content);
	else if (obj_node->element == rt_plane)
		t = pl_intersect(ray, obj_node->content);
	else if (obj_node->element == rt_square)
		t = sq_intersect(ray, obj_node->content);
	else if (obj_node->element == rt_triangle)
		t = tr_intersect(ray, obj_node->content);
	return (t);
}

void			ray_intersect(t_ray *ray, t_list *obj_node,
							t_hit *hit)
{
	double		t;

	hit->t = +INFINITY;
	while (obj_node)
	{
		t = one_obj_intersect(ray, obj_node);
		if (t >= 0 && t < hit->t)
		{
			hit->t = t;
			hit->obj = obj_node;
		}
		obj_node = obj_node->next;
	}
	if (isinf(hit->t))
		hit->t = -1;
	else
		set_hit(hit, ray);
}

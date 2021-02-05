/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:09:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 17:08:49 by hlimouni         ###   ########.fr       */
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

void			set_cy_normal(t_cylinder *cy, t_hit *hit)
{
	t_vect		center_to_hit;

	center_to_hit = vect_diff(hit->ray_obj, cy->origin);
	hit->normal = vect_unit(vect_diff(center_to_hit,
				vect_const_prod(vect_dot(cy->axis, center_to_hit), cy->axis)));
}

void			set_hit(t_hit *hit, t_ray *ray)
{
	void		*obj;

	obj = hit->obj->content;
	hit->ray_dir = ray->dir;
	hit->ray_obj = vect_const_prod(hit->t, ray->dir);
	hit->ray_obj = vect_sum(ray->origin, hit->ray_obj);
	hit->view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	hit->cam_up = ray->cam_up;
	set_hit_color(hit);
	if (hit->obj->element == rt_sphere)
		hit->normal = vect_unit(vect_diff(hit->ray_obj, ((t_sphere *)obj)->o));
	else if (hit->obj->element == rt_cylinder)
		set_cy_normal(obj, hit);
	else if (hit->obj->element == rt_plane)
		hit->normal = ((t_plane *)obj)->n;
	else if (hit->obj->element == rt_square)
		hit->normal = ((t_square *)obj)->normal;
	else if (hit->obj->element == rt_triangle)
		hit->normal = ((t_triangle *)obj)->normal;
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

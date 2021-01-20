/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:09:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 12:39:43 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



double			one_obj_intersect(t_ray *ray, t_list *obj_node)
{
	double		hit;

	if (obj_node->element == rt_sphere)
		t = sp_intersect2(ray, obj_node->content);
	else if (obj_node->element == rt_cylinder)
		t = cy_intersect2(ray, obj_node->content);
	else if (obj_node->element == rt_plane)
		t = pl_intersect2(ray, obj_node->content);
	else if (obj_node->element == rt_square)
		t = sq_intersect2(ray, obj_node->content);
	else if (obj_node->element == rt_triangle)
		t = tr_intersect2(ray, obj_node->content);
	return (t);
}

void			ray_intersect(t_ray *ray, t_list *obj_node, t_hit *hit)
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
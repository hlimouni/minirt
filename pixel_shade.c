/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:01:40 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/29 11:04:57 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect				phong_diffuse_specular(t_hit *hit, t_light *light,
											t_vect color)
{
	t_vect			diffuse_specular;
	double			refle_cst;
	t_vect			reflect;
	t_vect			diffuse;
	double			specular;

	diffuse = vect_const_prod(DIFU_C, color);
	refle_cst = 2 * vect_dot(hit->normal, hit->to_light);
	reflect = vect_const_prod(refle_cst, hit->normal);
	reflect = vect_diff(reflect, hit->to_light);
	reflect = vect_unit(reflect);
	specular = vect_dot(hit->view, reflect);
	specular = SPEC_C * pow(specular, SHINE);
	diffuse_specular = vect_const_sum(specular, diffuse);
	hit->surface_illumi = fmax(0, vect_dot(hit->normal, hit->to_light));
	diffuse_specular = vect_const_prod(hit->surface_illumi, diffuse_specular);
	diffuse_specular = vect_prod(light->coeff, diffuse_specular);
	return (diffuse_specular);
}

int					shadow_intersect(t_hit *hit, t_list *obj_node,
										t_light *light)
{
	t_ray			sh_ray;
	double			o_l_dis;
	double			t;

	sh_ray.cam_up = hit->cam_up;
	sh_ray.origin = vect_sum(hit->ray_obj, vect_const_prod(BIAS, hit->normal));
	sh_ray.dir = vect_unit(vect_diff(light->l, hit->ray_obj));
	hit->to_light = sh_ray.dir;
	o_l_dis = vect_norm(vect_diff(light->l, sh_ray.origin));
	while (obj_node)
	{
		if ((t = one_obj_intersect(&sh_ray, obj_node)) >= 0 && t < o_l_dis)
			return (1);
		obj_node = obj_node->next;
	}
	return (0);
}

int					pixel_shade(t_hit *hit, t_scene *scene)
{
	t_list			*light_lst;
	t_light			*light;
	t_vect			amb;
	t_vect			difu_spec;
	t_vect			color;

	light_lst = scene->lights;
	amb = vect_prod(scene->amb->coeff, hit->color);
	difu_spec = (t_vect){.x = 0, .y = 0, .z = 0};
	while (light_lst)
	{
		light = light_lst->content;
		if (shadow_intersect(hit, scene->objs, light) == 0)
		{
			difu_spec = vect_sum(difu_spec,
				phong_diffuse_specular(hit, light, hit->color));
		}
		light_lst = light_lst->next;
	}
	color = vect_sum(amb, difu_spec);
	return (vectoi(color));
}

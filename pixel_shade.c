/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:01:40 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 16:46:15 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect				phong_diffuse_specular(t_hit *hit, t_ray *ray,
										t_light *light, t_vect color)
{
	t_vect			diffuse_specular;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = hit->to_light;
	shade.diffuse = vect_const_prod(DIFU_C, color);
	shade.view = hit->view;
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * pow(shade.specular, SHINE);
	diffuse_specular = vect_const_sum(shade.specular, shade.diffuse);
	shade.surface_illum = fmax(0, vect_dot(shade.normal, shade.to_light));
	diffuse_specular = vect_const_prod(shade.surface_illum, diffuse_specular);
	diffuse_specular = vect_prod(light->coeff, diffuse_specular);
	return (diffuse_specular);
}

t_vect				phong_diffuse_specular2(t_hit *hit, t_ray *ray,
											t_light *light, t_vect color)
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
	float			bias;

	bias = 1e-5;
	sh_ray.origin = vect_sum(hit->ray_obj, vect_const_prod(bias, hit->normal));
	sh_ray.dir = vect_unit(vect_diff(light->l, hit->ray_obj));
	hit->to_light = sh_ray.dir;
	while (obj_node)
	{
		if (one_obj_intersect(&sh_ray, obj_node) >= 0)
			return (1);
		obj_node = obj_node->next;
	}
	return (0);
}

int					pixel_shade(t_hit *hit, t_ray *ray, t_scene *scene)
{
	t_list			*light_lst;
	t_light			*light;
	t_vect			amb;
	t_vect			difu_spec;
	t_vect			color;

	light_lst = scene->lights;
	amb = vect_prod(scene->amb->coeff, hit->color);
	while (light_lst)
	{
		light = light_lst->content;
		if (shadow_intersect(hit, scene->objs, light) == 0)
		{
			difu_spec = phong_diffuse_specular(hit, ray, light, hit->color);
			color = vect_sum(amb, difu_spec);
		}
		light_lst = light_lst->next;
	}
	return (vectoi(color));
}

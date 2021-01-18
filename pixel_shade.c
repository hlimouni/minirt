/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:01:40 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/18 15:49:59 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_cy_normal(t_hit *hit, t_cylinder *cy)
{
	hit->normal = vect_diff(hit->ray_obj, cy->origin);
	hit->normal = vect_diff(hit->normal,
		vect_const_prod(vect_dot(cy->axis, hit->normal), cy->axis));
	hit->normal = vect_unit(hit->normal);
}

void				set_planar_normals(t_vect og_norml, t_hit *hit, t_ray *ray)
{
	if (vect_dot(og_norml, hit->view) < 0)
		hit->normal = vect_const_prod(-1, og_norml);
	else
		hit->normal = og_norml;
}

void				set_hit_color(t_hit *hit)
{
	void			*obj;

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

void				set_hit(t_hit *hit, t_ray *ray)
{
	void			*obj;

	obj = hit->obj->content;
	hit->ray_obj = vect_const_prod(hit->t, ray->dir);
	hit->ray_obj = vect_sum(ray->origin, hit->ray_obj);
	hit->view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	set_hit_color(hit);
	if (hit->obj->element == rt_sphere)
		hit->normal = vect_unit(vect_diff(hit->ray_obj, ((t_sphere *)obj)->o));
	else if (hit->obj->element == rt_cylinder)
		set_cy_normal(hit, obj);
	else if (hit->obj->element == rt_plane)
		set_planar_normals(((t_plane *)obj)->n, hit, ray);
	else if (hit->obj->element == rt_square)
		set_planar_normals(((t_square *)obj)->normal, hit, ray);
	else if (hit->obj->element == rt_triangle)
		set_planar_normals(((t_triangle *)obj)->normal, hit, ray);
}

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

t_vect				sp_lighting(t_hit *hit, t_ray *ray, t_light *light,
								t_sphere *sp)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fmax(0, vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, sp->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * fmax(0, pow(shade.specular, SHINE));
	vect_dot(shade.normal, shade.to_light) < 0 ? (shade.specular = 0) : 0;
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
}

t_vect				pl_lighting(t_hit *hit, t_ray *ray, t_light *light,
								t_plane *pl)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fabs(vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, pl->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * pow(shade.specular, SHINE);
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
}

t_vect				cy_lighting(t_hit *hit, t_ray *ray, t_light *light,
							t_cylinder *cy)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fmax(0, vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, cy->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * fmax(0, pow(shade.specular, SHINE));
	vect_dot(shade.normal, shade.to_light) < 0 ? (shade.specular = 0) : 0;
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
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

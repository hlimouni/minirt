/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:01:40 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/17 17:01:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	amb_shading(t_amb *amb, int obj_color)
{
	t_vect		ambience;
	t_vect		amb_light_ratio;
	t_vect		intensity;

	amb_light_ratio = vect_const_prod(1.0/255.0, itovect(amb->color));
	intensity = vect_const_prod(amb->intensity, amb_light_ratio);
	ambience = vect_prod(itovect(obj_color), intensity);
	return (ambience);
}

t_vect	amb_shading2(t_amb *amb, t_vect obj_color)
{
	t_vect		ambience;
	t_vect		amb_light_ratio;
	t_vect		intensity;

	amb_light_ratio = vect_const_prod(1.0/255.0, itovect(amb->color));
	intensity = vect_const_prod(amb->intensity, amb_light_ratio);
	ambience = vect_prod(obj_color, intensity);
	return (ambience);
}



// t_vect	diffuse_shading(t_ray ray, t_vect normal, t_vect to_light)
// {
// 	t_vect	diffuse;


// }

/*
** t_vect	diffuse_shading()
** {}
*/

// t_ray		ray_build(float t, t_cam *cam, t_vect ray_screen)
// {
// 	t_ray	ray;

// 	ray.t = t;
// 	ray.origin = cam->c;
// 	ray.screen = ray_screen;
// 	ray.hit = vect_diff(ray_screen, cam->c);
// 	ray.hit = vect_const_prod(t, ray);
// 	ray.hit = vect_sum(cam->c, ray);
// 	return (ray);
// }

t_vect	hit_point(double t, t_ray *ray)
{
	t_vect	hit;

	hit = vect_const_prod(t, ray->dir);
	hit = vect_sum(ray->origin, hit);
	return (hit);
}

void	set_cy_normal(t_hit *hit, t_cylinder *cy)
{
	hit->normal = vect_diff(hit->ray_obj, cy->origin);
	hit->normal = vect_diff(hit->normal,
		vect_const_prod(vect_dot(cy->axis, hit->normal), cy->axis));
	hit->normal = vect_unit(hit->normal);
}

void			set_hit(t_hit *hit, t_ray *ray)
{
	void		*obj;
	t_cylinder	*cy;

	obj = hit->obj->content;
	hit->ray_obj = vect_const_prod(t, ray->dir);
	hit->ray_obj = vect_sum(ray->origin, hit->ray_obj);
	if (hit->obj->element == rt_sphere)
		hit->normal = vect_unit(vect_diff(hit->ray_obj, ((t_sphere *)obj)->o);
	else if (hit->obj->element == rt_cylinder)
	{
		cy = obj;
		hit->normal = vect_diff(hit->ray_obj, cy->origin);
		hit->normal = vect_diff(hit->normal,
			vect_const_prod(vect_dot(cy->axis, hit->normal), cy->axis));
		hit->normal = vect_unit(hit->normal);
	}
	else if (hit->obj->element == rt_plane)
		hit->normal = ((t_plane *)obj)->n;
	else if (hit->obj->element == rt_square)
		hit->normal = ((t_square *)obj)->normal;
	else if (hit->obj->element == rt_triangle)
		hit->normal = ((t_triangle *)obj)->normal;
}

t_vect			phong_diffuse_specular(t_hit *hit, t_ray *ray, t_light *light, t_vect color)
{
	t_vect			diffuse_specular;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
//	shade.difuse_cst = DIFU_C * fmax(0, vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(DIFU_C, color);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * pow(shade.specular, SHINE);
	diffuse_specular = vect_const_sum(shade.specular, shade.diffuse);
	shade.surface_illum = vect_dot(shade.normal, shade.to_light);
	diffuse_specular = vect_const_prod(shade.surface_illum, diffuse_specular);
	diffuse_specular = vect_prod(light->coeff, diffuse_specular);
	return (diffuse_specular);	
}

t_vect			sp_lighting(t_hit *hit, t_ray *ray, t_light *light, t_sphere *sp)
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


int	sp_shading(float t, t_light *light, t_cam *cam, t_sphere sp,
					t_amb amb, t_vect ray_screen)
{
	int			color;
	t_vect		ambiant;
	t_vect		diffuse;
	double		specular;
	t_vect		r;
	t_vect		v;
	t_vect		ray_object;
	t_vect		n;
	t_vect		l;
	t_vect		color_vect;
	float		shade;

	diffuse = itovect(0);
//	ambiant = rgb_const_prod(1/255, ambiant);
	ambiant = vect_const_prod(1.0/255.0, itovect(amb.color));
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_const_prod(amb.intensity, ambiant);
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_prod(itovect(sp.color), ambiant);
//	printf("the ambiant is %#08x\n", ambiant);

	ray_object = vect_unit(vect_diff(ray_screen, cam->c));
	ray_object = vect_const_prod(t, ray_object);
	ray_object = vect_sum(cam->c, ray_object);
	n = vect_diff(ray_object, sp.o);
	n = vect_unit(n);
	l = vect_diff(light->l, ray_object);
	l = vect_unit(l);
	shade = light->intensity * fmax(0, vect_dot(n, l));
	//printf("shade of the diffuse %f\n", shade);
	diffuse = vect_const_prod(shade, itovect(sp.color));
	v = vect_unit(vect_diff(cam->c ,ray_object));
	r = vect_unit(vect_sum(l, v));
	shade = vect_dot(n, r);
	/*
	shade = 2 * vect_dot(n, l);
	r = vect_const_prod(shade, n);
	r = vect_unit(vect_diff(r, l));
	shade = vect_dot(v, r);
	*/
	//printf("dot prod of v and h %f\n", shade);
	specular = 150 * fmax(0, pow(shade, 50));
	//printf("shade of the specualr %f\n", shade);
	color_vect = vect_sum(ambiant, diffuse);
	vect_dot(n, l) < 0 ? (specular = 0) : 0;
	color_vect = vect_const_sum(specular, color_vect);
	// return (color);
	color = vectoi(color_vect);
	return (color);
}

int	pl_shading(float t, t_light *light, t_cam *cam, t_plane pl,
					t_amb amb, t_vect ray_screen)
{
	int			color;
	t_vect		ambiant;
	t_vect		diffuse;
	double		specular;
	t_vect		h;
	t_vect		v;
	t_vect		ray_object;
	t_vect		n;
	t_vect		l;
	t_vect		color_vect;
	float		shade;

	diffuse = itovect(0);
//	ambiant = rgb_const_prod(1/255, ambiant);
	ambiant = vect_const_prod(1.0/255.0, itovect(amb.color));
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_const_prod(amb.intensity, ambiant);
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_prod(itovect(pl.color), ambiant);
//	printf("the ambiant is %#08x\n", ambiant);

	ray_object = vect_unit(vect_diff(ray_screen, cam->c));
	ray_object = vect_const_prod(t, ray_object);
	ray_object = vect_sum(cam->c, ray_object);
	l = vect_diff(light->l, ray_object);
	l = vect_unit(l);
	// if (vect_dot(n, l) < 0)
	// 	n = vect_const_prod(-1.0, vect_unit(pl.n));
	// else
	n = vect_unit(pl.n);
	// shade = light->intensity * fmax(0, vect_dot(n, l));
	/*
	** fabs is applied to n dot l because in the case of a plane even if 
	** that dot is negative (light hits the plane from the outside layer)
	** we still need to shade the outside layer of the plane
	*/
	shade = light->intensity * fabs(vect_dot(n, l));
	//shade = light->intensity * fmax(0, vect_dot(n, l));
	//printf("the t solution is  %f\n", t);
	// printf("shade of the diffuse %f\n", shade);
	diffuse = vect_const_prod(shade, itovect(pl.color));
	v = vect_unit(vect_diff(cam->c ,ray_object));
	// h = vect_unit(vect_sum(l, v));
	// shade = vect_dot(n, h);
	//printf("the shade is %f\n", shade);
	shade = 2 * vect_dot(n, l);
	h = vect_const_prod(shade, n);
	//printf("the h vect now is [%f][%f][%f]\n", h.x, h.y, h.z);
	h = vect_unit(vect_diff(h, l));
	//printf("the h vect now is [%f][%f][%f]\n", h.x, h.y, h.z);
	shade = vect_dot(v, h);
	//printf("dot prod of v and h %f\n", shade);
	specular = 150 * pow(shade, 5000);
	// printf("the specualr %f\n", specular);
	color_vect = vect_sum(ambiant, diffuse);
	//vect_dot(n, l) < 0 ? (shade = 0) : 0;
	// specular = 0;
	color_vect = vect_const_sum(specular, color_vect);
	// return (color);
	color = vectoi(color_vect);
	return (color);
}

t_vect			pl_lighting(t_hit *hit, t_ray *ray, t_light *light, t_plane *pl)
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

int	cy_shading(float t, t_light *light, t_cam *cam, t_cylinder cy,
					t_amb amb, t_vect ray_screen)
{
	int			color;
	t_vect		ambiant;
	t_vect		diffuse;
	double		specular;
	t_vect		r;
	t_vect		v;
	t_vect		ray_object;
	t_vect		n;
	t_vect		l;
	t_vect		color_vect;
	float		shade;

	diffuse = itovect(0);
//	ambiant = rgb_const_prod(1/255, ambiant);
	ambiant = vect_const_prod(1.0/255.0, itovect(amb.color));
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_const_prod(amb.intensity, ambiant);
//	printf("the ambiant is %#08x\n", ambiant);
	ambiant = vect_prod(itovect(cy.color), ambiant);
//	printf("the ambiant is %#08x\n", ambiant);

	ray_object = vect_unit(vect_diff(ray_screen, cam->c));
	ray_object = vect_const_prod(t, ray_object);
	ray_object = vect_sum(cam->c, ray_object);
	cy.axis = vect_unit(cy.axis);
	n = vect_diff(ray_object, cy.origin);
	n = vect_diff(n, vect_const_prod(vect_dot(cy.axis, n), cy.axis));
	n = vect_unit(n);
	l = vect_diff(light->l, ray_object);
	l = vect_unit(l);
	shade = light->intensity * fmax(0, vect_dot(n, l));
	//printf("shade of the diffuse %f\n", shade);
	diffuse = vect_const_prod(shade, itovect(cy.color));
	v = vect_unit(vect_diff(cam->c ,ray_object));
	r = vect_unit(vect_sum(l, v));
	shade = vect_dot(n, r);
	/*
	shade = 2 * vect_dot(n, l);
	r = vect_const_prod(shade, n);
	r = vect_unit(vect_diff(r, l));
	shade = vect_dot(v, r);
	*/
	//printf("dot prod of v and h %f\n", shade);
	specular = 150 * fmax(0, pow(shade, 50));
	//printf("shade of the specualr %f\n", shade);
	color_vect = vect_sum(ambiant, diffuse);
	vect_dot(n, l) < 0 ? (specular = 0) : 0;
	color_vect = vect_const_sum(specular, color_vect);
	// return (color);
	color = vectoi(color_vect);
	return (color);
}

t_vect			cy_lighting(t_hit *hit, t_ray *ray, t_light *light, t_cylinder *cy)
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

int		pixel_shade(t_hit *hit, t_ray *ray, t_scene *scene, t_list *obj)
{
	
}


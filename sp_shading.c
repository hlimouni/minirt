/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_shading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:00:56 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/11 16:20:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_vect			itovect(int color)
{
	t_vect			vect;
	unsigned char	*rgb;

	rgb = (unsigned char *)(&color);
	vect.x = (double)rgb[2];
	vect.y = (double)rgb[1];
	vect.z = (double)rgb[0];
	return (vect);
}

int				vectoi(t_vect vect)
{
	int		red;
	int 	green;
	int 	blue;
	int		color;
	double	x;
	double	y;
	double	z;

	if ((x = vect.x) > 255.0)
		x = 255.0;
	if ((y = vect.y) > 255.0)
		y = 255.0;
	if ((z = vect.z) > 255.0)
		z = 255.0;
	red = (int)x;
	green = (int)y;
	blue = (int)z;
	color = (red << 16 | green << 8 | blue);
	return (color);
}

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

t_vect	hit_point(float t, t_ray *ray)
{
	t_vect	hit;

	hit = vect_const_prod(t, ray->dir);
	hit = vect_sum(ray->origin, hit);
	return (hit);
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
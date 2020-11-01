/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_shading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:00:56 by hlimouni          #+#    #+#             */
/*   Updated: 2020/10/31 19:38:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_vect			itovect(int color)
{
	t_vect			vect;
	unsigned char	*rgb;

	rgb = (unsigned char *)(&color);
	vect.x = (float)rgb[2];
	vect.y = (float)rgb[1];
	vect.z = (float)rgb[0];
	return (vect);
}

int				vectoi(t_vect vect)
{
	int		red;
	int 	green;
	int 	blue;
	int		color;
	float	x;
	float	y;
	float	z;

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

t_vect	amb_shading(t_amb amb, int obj_color)
{
	t_vect		ambience;
	t_vect		amb_light_ratio;
	t_vect		intensity;

	amb_light_ratio = vect_const_prod(1.0/255.0, itovect(amb.color));
	intensity = vect_const_prod(amb.intensity, amb_light_ratio);
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

t_vect	ray_hit_point(float t, t_vect ray_screen, t_cam *cam)
{
	t_vect	ray;

	ray = vect_diff(ray_screen, cam->c);
	ray = vect_const_prod(t, ray);
	ray = vect_sum(cam->c, ray);
	return (ray);
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
	t_vect		ray;
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

	ray = vect_diff(ray_screen, cam->c);
	ray = vect_const_prod(t, ray);
	ray = vect_sum(cam->c, ray);
	n = vect_diff(ray, sp.o);
	n = vect_unit(n);
	l = vect_diff(light->l, ray);
	l = vect_unit(l);
	shade = light->intensity * fmax(0, vect_dot(n, l));
	//printf("shade of the diffuse %f\n", shade);
	diffuse = vect_const_prod(shade, itovect(sp.color));
	v = vect_unit(vect_diff(cam->c ,ray));
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
	// t_vect		specular;
	t_vect		h;
	t_vect		v;
	t_vect		ray;
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

	ray = vect_diff(ray_screen, cam->c);
	ray = vect_const_prod(t, ray);
	ray = vect_sum(cam->c, ray);
	n = vect_unit(pl.n);
	l = vect_diff(light->l, ray);
	l = vect_unit(l);
	shade = light->intensity * fmax(0, vect_dot(n, l));
	//printf("shade of the diffuse %f\n", shade);
	diffuse = vect_const_prod(shade, itovect(pl.color));
	v = vect_unit(vect_diff(cam->c ,ray));
	shade = 2 * vect_dot(n, l);
	h = vect_const_prod(shade, n);
	//printf("the h vect now is [%f][%f][%f]\n", h.x, h.y, h.z);
	h = vect_unit(vect_diff(h, l));
	//printf("the h vect now is [%f][%f][%f]\n", h.x, h.y, h.z);
	shade = vect_dot(v, h);
	//printf("dot prod of v and h %f\n", shade);
	shade = 190 * fmax(0, pow(shade, 20));
	//printf("shade of the specualr %f\n", shade);
	color_vect = vect_sum(ambiant, diffuse);
	vect_dot(n, l) < 0 ? (shade = 0) : 0;
	color_vect = vect_const_sum(shade, color_vect);
	// return (color);
	color = vectoi(color_vect);
	return (color);
}
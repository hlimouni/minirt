/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_build2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:32:27 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/11 16:12:29 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	mat_vect_prod(t_mat3x3	mat, t_vect	v)
{
	t_vect	prod;

	prod.x = vect_dot(mat.line1, v);
	prod.y = vect_dot(mat.line2, v);
	prod.z = vect_dot(mat.line3, v);
	return (prod);
}

int		is_vect_null(t_vect *vect)
{
	return (vect->x == 0 && vect->y == 0 && vect->z == 0)
}

t_vect	cam_ray_build2(int i, int j, t_cam *cam, float w, float h)
{
	t_vect		p;
	t_vect		tmp;
	t_vect		ray_screen;
	float		alpha;
    	t_vect  	cam_forward;
    	t_vect  	cam_up;
    	t_vect  	cam_right;
	t_mat3x3	mat;

	alpha = (cam->fov * M_PI) / 180.0;
	p.x = (2 * (i + 0.5) / w - 1) * (w / h) * tan(alpha / 2);
	p.y = (1 - 2 * (j + 0.5) / h) * tan(alpha / 2);
	p.z = -1;
    cam_forward = vect_unit(vect_const_prod(-1, cam->l));
	tmp = vect_cross(cam->l, itovect(0x000100));
	if (is_vect_equal(tmp, itovect(0)))
	{
		if (vect_dot(cam->l, itovect(0x000100)) > 0)
			tmp = vect_const_prod(-1, itovect(0x010000));
		else
			tmp = itovect(0x010000);
	}
	else
		tmp = itovect(0x000100);
    cam_right = vect_unit(vect_cross(tmp, cam_forward));
    cam_up = vect_unit(vect_cross(cam_forward, cam_right));
	cam->up = cam_up;
	mat.line1.x = cam_right.x;
	mat.line1.y = cam_up.x;
	mat.line1.z = cam_forward.x;
	mat.line2.x = cam_right.y;
	mat.line2.y = cam_up.y;
	mat.line2.z = cam_forward.y;
	mat.line3.x = cam_right.z;
	mat.line3.y = cam_up.z;
	mat.line3.z = cam_forward.z;
	ray_screen = vect_sum(cam->c, mat_vect_prod(mat, p));
	return (ray_screen);
}

t_vect	pixel_to_vect(int x, int y, t_resolution *res, double fov)
{
	t_vect	pixel;
	double	w;
	double	h;

	w = res->width;
	h = res->height;
	pixel.x = (2 * (i + 0.5) / w - 1) * (w / h) * tan(fov / 2);
	pixel.y = (1 - 2 * (j + 0.5) / h) * tan(fov / 2);
	pixel.z = -1;
	return (pixel);
}

t_vect	tmp_vect_set(t_vect *orient)
{
	t_vect	tmp;
	t_vect	cross;

	tmp = (t_vect){.x = 0, .y = 1, .z = 0};
	cross = vect_cross(*orient, tmp);
	if (is_vect_null(cross))
	{
		if (vect_dot(*orient, tmp) > 0)
			tmp = (t_vect){.x = -1, .y = 0, .z = 0};
		else
			tmp = (t_vect){.x = 1, .y = 0, .z = 0};
	}
	return (tmp);
}

t_ray	cam_ray_build3(int i, int j, t_cam *cam, t_resolution *res)
{
	t_vect		pixel;
    t_vect  	forward;
    t_vect  	right;
	t_mat3x3	mat;
	t_ray		ray;

	pixel = pixel_to_vect(i, j, res, cam->fov);
    forward = vect_unit(vect_const_prod(-1, cam->l));
	right = vect_cross(tmp_vect_set(cam->l), forward);
    right = vect_unit(right);
    cam->up = vect_unit(vect_cross(forward, right));
	mat.line1 = (t_vect){.x = right.x, .y = up.x, .z = forward.x};
	mat.line2 = (t_vect){.x = right.y, .y = up.y, .z = forward.y};
	mat.line3 = (t_vect){.x = right.z, .y = up.z, .z = forward.z};
	ray.screen = vect_sum(cam->c, mat_vect_prod(mat, pixel));
	ray.origin = cam->c;
	ray.dir = vect_unit(vect_diff(ray.screen, ray.origin));
	return (ray);
}

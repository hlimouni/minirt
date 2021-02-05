/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:15:39 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 15:52:12 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vect	pixel_to_vect(int i, int j, t_resolution *res, double fov)
{
	t_vect		pixel;
	double		w;
	double		h;

	w = res->width;
	h = res->height;
	pixel.x = (2 * (i + 0.5) / w - 1) * (w / h) * tan(fov / 2);
	pixel.y = (1 - 2 * (j + 0.5) / h) * tan(fov / 2);
	pixel.z = -1;
	return (pixel);
}

static t_vect	tmp_vect_set(t_vect *orient)
{
	t_vect		tmp;
	t_vect		cross;

	tmp = (t_vect){.x = 0, .y = 1, .z = 0};
	cross = vect_cross(*orient, tmp);
	if (is_vect_null(cross))
	{
		if (vect_dot(*orient, tmp) > 0)
			tmp = (t_vect){.x = 0, .y = 0, .z = -1};
		else
			tmp = (t_vect){.x = 0, .y = 0, .z = 1};
	}
	return (tmp);
}

void			cam_ray_build(int pxl[], t_cam *cam, t_resolution *res,
						t_ray *ray)
{
	t_vect		pixel;
	t_vect		forward;
	t_vect		right;
	t_mat3x3	mat;

	pixel = pixel_to_vect(pxl[i_pxl], pxl[j_pxl], res, cam->fov);
	forward = vect_unit(vect_const_prod(-1, cam->l));
	right = vect_cross(tmp_vect_set(&(cam->l)), forward);
	right = vect_unit(right);
	ray->cam_up = vect_unit(vect_cross(forward, right));
	mat.line1 = (t_vect){.x = right.x, .y = (ray->cam_up).x, .z = forward.x};
	mat.line2 = (t_vect){.x = right.y, .y = (ray->cam_up).y, .z = forward.y};
	mat.line3 = (t_vect){.x = right.z, .y = (ray->cam_up).z, .z = forward.z};
	ray->screen = vect_sum(cam->c, mat_vect_prod(mat, pixel));
	ray->origin = cam->c;
	ray->dir = vect_unit(vect_diff(ray->screen, ray->origin));
}

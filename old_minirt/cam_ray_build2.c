/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_build2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:32:27 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 15:15:18 by hlimouni         ###   ########.fr       */
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

/*
int		is_vect_null(t_vect *vect)
{
	return (vect->x == 0 && vect->y == 0 && vect->z == 0)
}
*/

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


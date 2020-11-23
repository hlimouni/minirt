/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_build2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:32:27 by hlimouni          #+#    #+#             */
/*   Updated: 2020/11/22 20:38:13 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	cam_ray_build(int i, int j, t_cam *cam, float w, float h)
{
	float	px;
	float	py;
	t_vect	ray_screen;
	float	alpha;
    t_vect  cam_forward;
    t_vect  cam_up;
    t_vect  cam_right;

	cam->l = vect_unit(cam->l);
	alpha = (cam->fov * M_PI) / 180.0;
	px = (2 * (i + 0.5) / w - 1) * (w / h) * tan(alpha / 2);
	py = (1 - 2 * (j + 0.5) / h) * tan(alpha / 2);
    cam_forward = -cam->l;
    cam_right = vect_cross(cam_forward, itovect(0x000100);
    cam_up = vect_cross(cam_forward, cam_right);
    ray_screen.x = 
	// ray_screen.x = -cam->l.z * px - cam->l.x * cam->l.y * py + cam->l.x
	// 	+ cam->c.x;
	// ray_screen.y = (cam->l.x * cam->l.x + cam->l.z * cam->l.z) * py +
	// 	cam->l.y + cam->c.y;
	// ray_screen.z = cam->l.x * px - cam->l.y * cam->l.z * py +
	// 	cam->l.z + cam->c.z;
	return (ray_screen);
}
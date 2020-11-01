/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:37:18 by hlimouni          #+#    #+#             */
/*   Updated: 2020/03/12 21:53:54 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Cam_ray_build basically transforms the coordinates i, j in raster space of
**     the pixel into world space.
** px and py are in camera's relative coordinate system.
** The ray_screen vector results after applying rotation and translation of
** 		the pixel coordinates to the world coordinates.
*/

t_vect	cam_ray_build(int i, int j, t_cam *cam, float w, float h)
{
	float	px;
	float	py;
	t_vect	ray_screen;
	float	alpha;

	cam->l = vect_unit(cam->l);
	alpha = (cam->fov * M_PI) / 180.0;
	px = (2 * (i + 0.5) / w - 1) * (w / h) * tan(alpha / 2);
	py = (1 - 2 * (j + 0.5) / h) * tan(alpha / 2);
	ray_screen.x = -cam->l.z * px - cam->l.x * cam->l.y * py + cam->l.x
		+ cam->c.x;
	ray_screen.y = -(cam->l.x * cam->l.x + cam->l.z * cam->l.z) * py +
		cam->l.y + cam->c.y;
	ray_screen.z = cam->l.x * px - cam->l.y * cam->l.z * py +
		cam->l.z + cam->c.z;
	return (ray_screen);
}

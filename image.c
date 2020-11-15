/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:35:09 by hlimouni          #+#    #+#             */
/*   Updated: 2020/11/15 13:55:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/ft_printf.h"
#include "minilibx/mlx.h"
#include "minirt.h"
#include <stdio.h>

void	print_vect(t_vect v)
{
	printf("[%f]\n", v.x);
	printf("[%f]\n", v.y);
	printf("[%f]\n", v.z);
}

int	main(void)
{
	 void	*mlx_ptr;
	 void	*win_ptr;
	int		i;
	int		j;
	float	t;
	int		color;
	int		width = 1000;
	int		height = 800;
	// int		width = 44;
	// int		height = 38;
	t_plane	pl;
	t_cam	cam;
	t_sphere	sp;
	t_amb		amb;
	t_light		light;
	t_square	sq;
	t_vect	c, l, o, ray,li, p, n, origin, normal;

/*
** Ambiant light
*/
amb.intensity = 0.089;
amb.color = 0xffffff;

/*
** light coordintates
*/
li.x = 40;
li.y = 0;
li.z = 0;
light.l = li;
light.intensity = 1;
light.color = 0xffffff;
/*
** Square center coordinates
*/
origin.x = 0;
origin.y = 0;
origin.z = 0;
sq.origin = origin;
/*
** Square normal coordinates
*/
normal.x = -1;
normal.y = 0;
normal.z = 0;
sq.normal = normal;
/*
** square side and color
*/
sq.side = 0.6;
sq.color = 0x8A2BE2;
/*
** Plane's P coordinates
*/
p.x = 0;
p.y = 0;
p.z = 0;
pl.p = p;
/*
** Plane's normal
*/
n.x = -1;
n.y = 0;
n.z = 0;
pl.n = n;
/*
** Plane's color;
*/
pl.color = 0x8A2BE2;

/*
** camera coordinates
*/
/**********************/
	c.x = 3;
	c.y = 0;
	c.z = 0;
/**********************/
	cam.c = c;
/**********************/
/*
** camera look at vector coordinates
*/
/**********************/
	l.x = -1;
	l.y = 0;
	l.z = 0;
/**********************/
	cam.l = l;
/**********************/
/*
** camera field of view
*/
/**********************/
	cam.fov = 70;
/**********************/

	cam.next = NULL;

/**********************/
/*
** sphere center coordinates
*/
/**********************/
	o.x = 0;
	o.y = 0;
	o.z = 0;
/**********************/
	sp.o = o;
/**********************/
/*
** sphere Diameter
*/
/**********************/
	sp.d = 2;
/**********************/
/*
** sphere Color
*/
/**********************/
	sp.color = 0x8A2BE2;
/**********************/

	// ray = cam_ray_build(i, j, &cam, width, height);
	// print_vect(ray);
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "image");
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
		 	ray = cam_ray_build(i, j, &cam, width, height);
			// if ((t = sp_intersect(ray, &cam, sp)) >= 0.0)
			// {
			// 	color = sp_shading(t, &light, &cam, sp, amb, ray);
			// 	mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			// }

			// if ((t = pl_intersect(ray, &cam, pl)) >= 0.0)
			// {
			// 	color = pl_shading(t, &light, &cam, pl, amb, ray);
			// 	mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			// }

			if ((t = sq_intersect(ray, &cam, sq)) >= 0.0)
			{
			//	color = 0x8A2BE2;
				color = pl_shading(t, &light, &cam, pl, amb, ray);
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			}


			// else
			// 	mlx_pixel_put(mlx_ptr, win_ptr,i , j, 0x4a4a4a);

			i++;
		}
		j++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}

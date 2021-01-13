/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:03:17 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/13 12:38:59 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_mlx_data(t_mlibx *mlx, t_resolution *res)
{
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, res->width, res->height, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->ptr, res->width, res->height);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp,
		&mlx->line_len, &mlx->endian);
}

int		ray_trace(int i, int j, t_scene *scene, t_mlibx *mlx)
{
	t_ray	ray;
	t_list	*cam;

	cam = scene->cams;
	ray = cam_ray_build3(i, j, cam, scene->res);
}

t_cam	*rt_cam_switch(t_scene *scene)
{
	t_cam	*cam;

	cam = scene->cams;
}

void	create_rt_image(t_scene *scene, t_mlibx *mlx)
{
	int	i;
	int	j;
	int	color;

	set_mlx_data(mlx, scene->res);
	j = 0;
	while (j < res->height)
	{
		i = 0;
		while (i < scene->res->width)
		{
			color = ray_trace(i, j, scene, mlx);
			mlx->img_data[j * scene->res->width + i] = color;
			i++;
		}
		j++;
	}
//	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
// 	mlx_loop(mlx->ptr);
}
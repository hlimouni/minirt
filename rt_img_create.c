/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:38:48 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 12:38:50 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					key_bind(int keycode, t_rt_data *data)
{
	static t_list	*cam_lst = data->scene->cams;
	
	if (keycode == K_SPACE)
	{
		if (!(cam_lst = cam_lst->next))
			cam_lst = data->scene->cams;
		img_array_set(cam_lst->content, data->scene, data->mlx->img_data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win_ptr,
			mlx->img_ptr, 0, 0);
	}
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx->ptr, data->mlx->win_ptr);
		rt_free_scene(data->scene);
		exit(0);
	}
	return (0);
}

int	close_bind(t_rt_data *data)
{
	rt_free_scene(data->scene);
	exit(0);	
}

void	img_array_set(t_cam *cam, t_scene *scene, int *img_data)
{
	int		i;
	int		j;
	t_hit	hit;
	t_ray	ray;
	double	t;

	j = 0;
	set_base_for_squares(cam, scene->objs);
	while (j < scene->res->height)
	{
		i = 0;
		while (i < scene->res->width)
		{
			cam_ray_build3((int[]){i, j}, cam, res, &ray);
			ray_intersect(&ray, scene->objs, &hit);
			if (hit.t >= 0)
			{
				hit.pxl_color = pixel_shade(&hit, &ray, scene);
				img_data[j * scene->res->width + i] = hit.pxl_color;
			}
			i++;
		}
		j++;
	}
}

void	rt_image_create(t_scene *scene, t_mlibx *mlx)
{
	t_resolution	*res;

	res = scene->res;
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, res->width, res->height, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->ptr, res->width, res->height);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp,
		&mlx->line_len, &mlx->endian);
	img_array_set(scene->cams->content, scene, mlx->img_data);
}

void	display_rt_image(t_mlibx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_do_key_autorepeatoff(data->mlx->ptr);
	mlx_hook(data->mlx->win_ptr, E_KEY_PRESS, 1L << 0, key_bind, data);
	mlx_hook(data->mlx->win_ptr, E_DESTROY, 1L << 17, close_bind, data);
 	mlx_loop(mlx->ptr);
}

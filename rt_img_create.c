/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:38:48 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/07 09:35:07 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				img_array_set(t_cam *cam, t_scene *scene, t_mlibx *mlx)
{
	int				i;
	int				j;
	t_hit			hit;
	t_ray			ray;

	j = 0;
	while (j < scene->res->height)
	{
		i = 0;
		while (i < scene->res->width)
		{
			cam_ray_build((int[]){i, j}, cam, scene->res, &ray);
			ray_intersect(&ray, scene->objs, &hit);
			if (hit.t >= 0)
			{
				hit.pxl_color = pixel_shade(&hit, scene);
				mlx->img_data[j * (mlx->line_len / 4) +
					i * (mlx->bbp / 32)] = hit.pxl_color;
			}
			i++;
		}
		j++;
	}
}

void				clear_image(t_scene *scene, t_mlibx *mlx)
{
	int				i;
	int				j;

	j = 0;
	while (j < scene->res->height)
	{
		i = 0;
		while (i < scene->res->width)
		{
			mlx->img_data[j * (mlx->line_len / 4) + i * (mlx->bbp / 32)] = 0;
			i++;
		}
		j++;
	}
}

void				rt_image_create(t_scene *scene, t_mlibx *mlx)
{
	t_resolution	*res;
	int				sizex;
	int				sizey;

	res = scene->res;
	mlx->ptr = mlx_init();
	mlx_get_screen_size(mlx->ptr, &sizex, &sizey);
	if (res->height == 0)
		res->height++;
	if (res->width == 0)
		res->width++;
	res->height > sizey ? (res->height = sizey) : 0;
	res->width > sizex ? (res->width = sizex) : 0;
	mlx->win_ptr = mlx_new_window(mlx->ptr, res->width, res->height, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->ptr, res->width, res->height);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp,
			&mlx->line_len, &mlx->endian);
	img_array_set(scene->cams->content, scene, mlx);
}

int					key_bind(int keycode, t_rt_data *data)
{
	static t_list	*cam_lst;
	static	int		firstcall;

	if (keycode == K_SPACE)
	{
		if (cam_lst == NULL && firstcall++ == 0)
			cam_lst = data->scene->cams->next;
		else if (cam_lst == NULL && firstcall)
			cam_lst = data->scene->cams;
		else
			cam_lst = cam_lst->next;
		cam_lst == NULL ? (cam_lst = data->scene->cams) : 0;
		clear_image(data->scene, data->mlx);
		img_array_set(cam_lst->content, data->scene, data->mlx);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win_ptr,
				data->mlx->img_ptr, 0, 0);
	}
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx->ptr, data->mlx->win_ptr);
		rt_free_scene(data->scene);
		exit(0);
	}
	return (0);
}

int					close_bind(t_rt_data *data)
{
	rt_free_scene(data->scene);
	exit(0);
}

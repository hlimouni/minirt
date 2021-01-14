/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:03:17 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/14 17:38:37 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_data_set(t_mlibx *mlx, t_resolution *res)
{
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, res->width, res->height, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->ptr, res->width, res->height);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp,
		&mlx->line_len, &mlx->endian);
}


int		get_pixel_color(int i, int j, t_scene *scene, t_mlibx *mlx)
{
	t_ray	ray;
	t_list	*cams;

	cam = scene->cams;
	mlx_key_hook(mlx->win_ptr, key_bind, param);
	ray = cam_ray_build3(i, j, cam, scene->res);
}

int	key_bind(int keycode, t_rt_data *data)
{
	static t_list *cam_lst = data->scene->cams;
	
	if (keycode == K_SPACE)
	{
		cam_lst = cam_lst->next;
		mlx_clear_window(data->mlx->ptr, data->mlx->win_ptr);
		img_array_set((t_cam *)cam_lst->content, data->scene,
			data->mlx->img_data);
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

int	rt_event_hooks(t_rt_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx->ptr);
	mlx_hook(data->mlx->win_ptr, E_KEY_PRESS, 1L<<0, key_bind, data);
	mlx_hook(data->mlx->win_ptr, E_DESTROY, 1L<<17, close_bind, data); 
}

void	img_array_set(t_cam *cam, t_scene *scene, int *img_data)
{
	int		i;
	int		j;
	t_hit	hit;
	t_ray	ray;
	double	t;

	j = 0;
	while (j < scene->res->height)
	{
		i = 0;
		while (i < scene->res->width)
		{
			ray = cam_ray_build3(i, j, cam, res);
			if ((hit = ray_intersect(&ray, scene->objs)).t >= 0)
			{
				hit.obj_color = pixel_shade(hit, ray, scene, hit.obj);
				img_data[j * scene->res->width + i] = hit.obj_color;
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
	img_array_set((t_cam *)scene->cams->content, scene, mlx->img_data);
}

//	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
//	mlx_key_hook(mlx.win_ptr, key_bind, NULL);
// 	mlx_loop(mlx->ptr);

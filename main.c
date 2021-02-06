/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:08:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/06 16:17:02 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				open_rt_file(int ac, char *av[])
{
	int		fd;

	if (ac == 1)
		rt_exit(nofile_err, 0, 0, NULL);
	if (ac > 3)
		rt_exit(many_args_err, 0, 0, NULL);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		rt_exit(open_err, 0, 0, NULL);
	if (read(fd, NULL, 0) < 0)
		rt_exit(read_err, 0, 0, NULL);
	if (!ft_strchr(av[1], '.') || ft_strcmp(ft_strrchr(av[1], '.'), ".rt"))
		rt_exit(format_err, 0, 0, NULL);
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		rt_exit(wrong_arg_err, 0, 0, NULL);
	return (fd);
}

void			rt_scene_initialize(t_scene *scene)
{
	scene->res = NULL;
	scene->amb = NULL;
	scene->cams = NULL;
	scene->lights = NULL;
	scene->objs = NULL;
}

void			rt_free_scene(t_scene *scene)
{
	ft_free_null((void **)&(scene->amb));
	ft_free_null((void **)&(scene->res));
	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->objs), free);
}

void			display_rt_image(t_scene *scene, t_mlibx *mlx)
{
	t_rt_data	data;

	data.scene = scene;
	data.mlx = mlx;
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_do_key_autorepeatoff(mlx->ptr);
	mlx_hook(mlx->win_ptr, E_KEY_PRESS, 1L << 0, key_bind, &data);
	mlx_hook(mlx->win_ptr, E_DESTROY, 1L << 17, close_bind, &data);
	mlx_loop(mlx->ptr);
}

int				main(int ac, char *av[])
{
	int			fd;
	t_scene		scene;
	t_mlibx		mlibx;

	fd = open_rt_file(ac, av);
	rt_scene_initialize(&scene);
	rt_parse(fd, &scene);
	rt_image_create(&scene, &mlibx);
	if (ac == 2)
		display_rt_image(&scene, &mlibx);
	if (ac == 3)
		save_rt_image(&mlibx, &scene);
	rt_free_scene(&scene);
	return (0);
}

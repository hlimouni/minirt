/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_codes_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:37:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/15 10:53:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_bind(int keycode, t_mlibx *mlx)
{
	int			i, j, width, height;
	static int	count = 0;
	
	mlx_get_screen_size(mlx->ptr, &width, &height);
	if (keycode == K_SPACE)
	{
		count++;
		fprintf(stderr, "S");
		if (count % 2 == 1)
			mlx_clear_window(mlx->ptr, mlx->win_ptr);
		else
		{
			j = 0;
			while (j < height)
			{
				i = 0;
				while (i < width)
				{
					mlx->img_data[j * width + i] = 0xFF0000;
					i++;
				}
				j++;
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		}
		
	}
	if (keycode == K_ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
		fprintf(stderr, "\nwindow closed through ESC\n");
		exit(0);
	}
	return (0);
}

int		rt_close(t_mlibx *mlx)
{
	fprintf(stderr, "\nwindow closed by red cross\n");
	exit(0);
}

int		main(void)
{
	t_mlibx		mlx;
	int			i;
	int			j;
	int			height;
	int			width;
	int			color;

	height = 111;
	width = 222;
	mlx.ptr = mlx_init();
	mlx_get_screen_size(mlx.ptr, &width, &height);
	mlx.win_ptr = mlx_new_window(mlx.ptr, width, height, "image");
	mlx.img_ptr = mlx_new_image(mlx.ptr, width, height);
	mlx.img_data = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bbp,
		&mlx.line_len, &mlx.endian);
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			color = 0xFF0000;
			mlx.img_data[j * width + i] = color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_do_key_autorepeatoff(mlx.ptr);
	mlx_hook(mlx.win_ptr, E_DESTROY, 1L<<17, rt_close, &mlx);
	mlx_hook(mlx.win_ptr, E_KEY_PRESS, 1L<<0, key_bind, &mlx);
	mlx_loop(mlx.ptr);
}

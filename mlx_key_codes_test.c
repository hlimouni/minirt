/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_codes_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:37:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/14 17:02:58 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_bind(int keycode, t_mlibx *mlx)
{
	if (keycode == 0x31)
		fprintf(stderr, "S");
	if (keycode == 0x35)
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
	mlx.win_ptr = mlx_new_window(mlx.ptr, width, height, "image");
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			color = 0xFF0000;
			mlx_pixel_put(mlx.ptr, mlx.win_ptr, i, j, color);
			i++;
		}
		j++;
	}
	mlx_hook(mlx.win_ptr, 17, 1L<<17, rt_close, &mlx);
	mlx_key_hook(mlx.win_ptr, key_bind, &mlx);
	mlx_loop(mlx.ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_codes_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:37:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/13 12:58:45 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define K_SPACE 0x31

int		key_bind(int keycode, void	*ptr)
{
	if (keycode == K_SPACE)
		printf("S");
	return (0);
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
	mlx_key_hook(mlx.win_ptr, key_bind, NULL);
	mlx_loop(mlx.ptr);
}
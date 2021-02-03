/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rt_image2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:43:52 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/03 23:20:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			ft_bmp_header(int fd, int x, int y)
{
	int		width;
	int		pad;
	char	s[54];

	width = x;
	pad = 0;
	ft_bzero(s, 54);
	s[0] = 0X42;
	s[1] = 0x4D;
	while ((3 * width + pad) % 4 != 0)
		pad++;
	s[2] = 3 * (width + pad) * x + 54;
	s[10] = 54;
	s[14] = 40;
	ft_memcpy(s + 18, &x, 4);
	ft_memcpy(s + 22, &y, 4);
	s[26] = 1;
	s[28] = 24;
	write(fd, s, 54);
	return (pad);
}

static void			save_to_screenshot(t_scene *scene, int fd, t_mlibx *mlx)
{
	char	*str;
	int		pad;
	int		j;
	int		i;
	char	*img_data;

	img_data = (char *)mlx->img_data;
	pad = ft_bmp_header(fd, scene->res->width, scene->res->height);
	j = scene->res->height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->res->width)
		{
			str = &img_data[j * mlx->line_len +
						i * (mlx->bbp / 8)];
			write(fd, str, 3);
			i++;
		}
		write(fd, "\0\0\0", pad);
		j--;
	}
}

void				ft_save_bmp(t_scene *scene)
{
	int			fd;

	fd = open("screen.bmp", O_RDWR | O_CREAT, 0666);
	save_to_screenshot(scene, fd, scene->res->width, scene->res->height);
}

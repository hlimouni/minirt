/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rt_image2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:43:52 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/04 22:30:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			bmp_header_set(int fd, int width, int height)
{
	int		width;
	int		pad;
	char	header[54];

	ft_bzero(header, 54);
	header[0] = 0x42;
	header[1] = 0x4D;
	pad = 0;
	while ((3 * width + pad) % 4 != 0)
		pad++;
	// header[2] = 3 * (width + pad) * x + 54;
	header[2] = (3 * width + pad) * height + 54;
	header[10] = 54;
	header[14] = 40;
	ft_memcpy(&header[18], &width, 4);
	ft_memcpy(&header[22], &height, 4);
	header[26] = 1;
	header[28] = 24;
	write(fd, header, 54);
	return (pad);
}

void			rt_image_create(t_scene *scene, t_mlibx *mlx)
{
	char	*str;
	int		pad;
	int		j;
	int		i;
	char	*img_data;
	int		fd;

	fd = open("image.bmp", O_RDWR | O_CREAT, 0666);
	img_data = (char *)(mlx->img_data);
	pad = bmp_header_set(fd, scene->res->width, scene->res->height);
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


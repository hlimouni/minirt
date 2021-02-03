/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rt_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:00:19 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/03 19:20:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int main(void)
// {
//     int j, i, row;
// 	char *header;
// 	int	 *img_data;
// 	int	 *pixel_arr;
//     int width = 100;
//     int height = 100;
//     int size = width * height * 4; //for 32-bit bitmap only

//     // char header[54] = { 0 };
// 	header = (char[54]){0};
// 	//BITMAPFILEHEADER 5 fields 14 bytes
// 	//from index 0 to index 13
//     ft_strlcpy(header, "BM", 2);//file type
//     ft_memset(&header[2],  (int)(54 + size), 1);//filesize = header + size of img_data
//     ft_memset(&header[10], (int)54, 1);//always 54 because the offset to img_data is always 54(header size)
// 	//BITMAPINFOHEADER 11 fields 40 bytes
// 	//from index 14 to index 53
//     ft_memset(&header[14], (int)40, 1);//always 40 = second header size
//     ft_memset(&header[18], (int)width, 1);
//     ft_memset(&header[22], (int)height, 1);
//     ft_memset(&header[26], (short)1, 1);//color plane should be one
//     ft_memset(&header[28], (short)32, 1);//32bit or bbp in the mlx
//     ft_memset(&header[34], (int)size, 1);//img_data size
// 	//rest can be set to zeros

//     unsigned char *pixels = malloc(size);
//     for(j = height - 1; j >= 0; j--) {
//         for(i = 0; i < width; i++) {
//             int p = (j * width + i) * 4;
//             pixels[p + 0] = 64; //blue
//             pixels[p + 1] = 128;//green
//             pixels[p + 2] = 192;//red

//         }
//     }
// 	j = height - 1;
// 	row = 0;
// 	while (j >= 0)
// 	{
// 		ft_memmove(&pixel_arr[row], &img_data[j * mlx->line_len], mlx->line_len);
// 		row += mlx->line_len;
// 		j--;
// 	}
//     FILE *fout = fopen("32bit.bmp", "wb");
//     fwrite(header, 1, 54, fout);
//     fwrite(pixels, 1, size, fout);
//     free(pixels);
//     fclose(fout);
//     return 0;
// }

void		save_rt_image(t_mlibx *mlx, t_scene *scene)
{
	int		i;
	int		j;
	int		p;
	char	*img_data;
	char	*header;
	char	*pixel_arr;
	int		size;
	int		fd;

	header = malloc(54);
	ft_memset(header, 0, 54);
	size = scene->res->height * scene->res->width * 4;
    ft_strlcpy(header, "BM", 2);
    ft_memset(&header[2],  (int)(54 + size), 1);
    ft_memset(&header[10], (int)54, 1);
    ft_memset(&header[14], (int)40, 1);
    ft_memset(&header[18], (int)(scene->res->width), 1);
    ft_memset(&header[22], (int)(scene->res->height), 1);
    ft_memset(&header[26], (short)1, 1);
    ft_memset(&header[28], (short)(32), 1);
    ft_memset(&header[34], (int)size, 1);
	if (!(pixel_arr = malloc(size)))
		rt_exit(alloc_err, 0, 0, NULL);
	j = scene->res->height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->res->width)
		{
			p = (j * scene->res->width + i) * 4;
			pixel_arr[p + 0] = 
			ft_memcpy(&pixel_arr[p], &(mlx->img_data)[j * scene->res->width + i], 4);
			i++;
		}
		j--;
	}
	fd = open("image.bmp", O_CREAT | O_WRONLY, 00644);
	write(fd, header, 54);
	write(fd, pixel_arr, size);
	free(pixel_arr);
	free(header);
	close(fd);
}
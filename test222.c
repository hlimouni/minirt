/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test222.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:25:10 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/30 11:59:05 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

char		**info_arr_set2(void)
{
	int			i;
	char			**info_arr;
	char			**data;
	int				end;

	info_arr = (char **)malloc(sizeof(char *) * (rt_elems_num + 1));
	info_arr[rt_camera] = (char *)malloc(sizeof(char) * (c_params_num + 1));
	info_arr[rt_ambiant] = (char *)malloc(sizeof(char) * (amb_params_num + 1));
	info_arr[rt_resolution] = (char *)malloc(sizeof(char) * (res_params_num + 1));
	info_arr[rt_light] = (char *)malloc(sizeof(char) * (l_params_num + 1));
	info_arr[rt_square] = (char *)malloc(sizeof(char) * (sq_params_num + 1));
	info_arr[rt_triangle] = (char *)malloc(sizeof(char) * (tr_params_num + 1));
	info_arr[rt_sphere] = (char *)malloc(sizeof(char) * (sp_params_num + 1));
	info_arr[rt_cylinder] = (char *)malloc(sizeof(char) * (cy_params_num + 1));
	info_arr[rt_plane] = (char *)malloc(sizeof(char) * (pl_params_num + 1));
	info_arr[rt_translation] = (char *)malloc(sizeof(char) * (tran_params_num + 1));
	info_arr[rt_rotation] = (char *)malloc(sizeof(char) * (rot_params_num + 1));
	info_arr[rt_elems_num] = NULL;
	
	data = (char*[])
	{
		(char[]){rt_camera, vector_type, vector_type, angle_type, -1},
		(char[]){rt_ambiant, ratio_type, rgb_type, -1},
		(char[]){rt_resolution, uint_type, uint_type, -1},
		(char[]){rt_light, vector_type, ratio_type, rgb_type, -1},
		(char[]){rt_square,
			vector_type, vector_type, udecimal_type, rgb_type, -1},
		(char[]){rt_triangle,
			vector_type, vector_type, vector_type, rgb_type, -1},
		(char[]){rt_sphere, vector_type, udecimal_type, rgb_type, -1},
		(char[]){rt_cylinder, vector_type, vector_type, udecimal_type,
			udecimal_type, rgb_type, -1},
		(char[]){rt_plane, vector_type, vector_type, rgb_type, -1},
		(char[]){rt_translation, ID_type, vector_type, -1},
		(char[]){rt_rotation, ID_type, angle_type, angle_type, angle_type, -1},
	};
	i = 0;
	while (i < rt_elems_num)
	{
		end = ft_datacpy(info_arr[i], data[i], -1, -1);
		info_arr[i][end] = -1;
		i++;
	}
	i = 0;
	while (data[rt_camera][i] >= 0)
	{
		printf("%d\n", data[rt_camera][i]);
		i++;
	}
	return (info_arr);
}

void	type_enum_print(int type)
{
	if (type == -1)
		printf("end");
	else if (type == ID_type)
	 	printf("ID");
	else if (type == vector_type)
	 	printf("vector");
	else if (type == decimal_type)
	 	printf("decimal");
	else if (type == udecimal_type)
	 	printf("udecimal");
	else if (type == rgb_type)
	 	printf("rgb");
	else if (type == ratio_type)
	 	printf("ratio");
	else if (type == angle_type)
	 	printf("angle");
	else if (type == uint_type)
	 	printf("uint");
	else
	{
		printf("not a valid type");
	}
}
void	elem_enum_print(int type)
{
	if (type == ID_type)
	 	printf("cam");
	else if (type == vector_type)
	 	printf("amb");
	else if (type == decimal_type)
	 	printf("resol");
	else if (type == udecimal_type)
	 	printf("light");
	else if (type == rgb_type)
	 	printf("square");
	else if (type == ratio_type)
	 	printf("triangle");
	else if (type == angle_type)
	 	printf("sphere");
	else if (type == uint_type)
	 	printf("cylinder");
	else if (type == uint_type + 1)
	 	printf("plane");
	else if (type == uint_type + 2)
	 	printf("transl");
	else if (type == uint_type + 3)
	 	printf("rotation");
	else if (type == uint_type + 4)
	 	printf("elem_num");
	else
	{
		printf("not a valid type");
	}
}
	
	// type == -1 ? printf("end") : 0;
	// type == ID_type ? printf("ID") : 0;
	// type == vector_type ? printf("vector") : 0;
	// type == decimal_type ? printf("decimal") : 0;
	// type == udecimal_type ? printf("u decimal") : 0;
	// type == rgb_type ? printf("rgb") : 0;
	// type == ratio_type ? printf("ratio") : 0;
	// type == angle_type ? printf("angle") : 0;
	// type == uint_type ? printf("uint") : 0;



void	free_info_arr(int ***info)
{

	int             i;

	i = 0;
	while ((*info)[i])
	{
	        free((*info)[i]);
	        (*info)[i] = NULL;
	        i++;
	}
	free(*info);
	*info = NULL;
}

int				main(void)
{
	int			i,j;
	char			**array;

	array = info_arr_set2();
	j = 0;
	while (array[j])
	{
		i = 0;
		elem_enum_print(array[j][i]);
		i++;
		printf(" ");
		while (array[j][i] >= 0)
		{
			type_enum_print(array[j][i]);
			printf(" ");
			i++;
		}
		j++;
		printf ("\n");
	}
	// i = 0;
	// while (i < cy_params_num)
	// {
	// 	printf("%d\n", arr[rt_cylinder][i]);
	// 	i++;
	// }
	// free_info_arr(&arr);
}

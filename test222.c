/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test222.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:25:10 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/29 19:13:38 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

t_info_arr		info_arr_set2(void)
{
	int			**arr;
	t_info_arr	info;

	arr = (int *[])
	{
		(int[]) {rt_camera, vector_type, vector_type, angle_type, -1},
		(int[]) {rt_ambiant, ratio_type, rgb_type, -1},
		(int[]) {rt_resolution, uint_type, uint_type, -1},
		(int[]) {rt_light, vector_type, ratio_type, rgb_type, -1},
		(int[]) {rt_square,
			vector_type, vector_type, udecimal_type, rgb_type, -1},
		(int[]) {rt_triangle,
			vector_type, vector_type, vector_type, rgb_type, -1},
		(int[]) {rt_sphere, vector_type, udecimal_type, rgb_type, -1},
		(int[]) {rt_cylinder, vector_type, vector_type, udecimal_type,
			udecimal_type, rgb_type, -1},
		(int[]) {rt_plane, vector_type, vector_type, rgb_type, -1},
		(int[]) {rt_translation, ID_type, vector_type, -1},
		(int[]) {rt_rotation, ID_type, angle_type, angle_type, angle_type, -1},
		(NULL)
	};
	info.arr = arr;
	return (info);
}

void	type_enum_print(int element)
{
	if (element == -1)
		printf("end");
	else if (element == ID_type)
	 	printf("ID");
	else if (element == vector_type)
	 	printf("vector");
	else if (element == decimal_type)
	 	printf("decimal");
	else if (element == udecimal_type)
	 	printf("udecimal");
	else if (element == rgb_type)
	 	printf("rgb");
	else if (element == ratio_type)
	 	printf("ratio");
	else if (element == angle_type)
	 	printf("angle");
	else if (element == uint_type)
	 	printf("uint");
	else
	{
		printf("not a valid type");
	}
	
	// element == -1 ? printf("end") : 0;
	// element == ID_type ? printf("ID") : 0;
	// element == vector_type ? printf("vector") : 0;
	// element == decimal_type ? printf("decimal") : 0;
	// element == udecimal_type ? printf("u decimal") : 0;
	// element == rgb_type ? printf("rgb") : 0;
	// element == ratio_type ? printf("ratio") : 0;
	// element == angle_type ? printf("angle") : 0;
	// element == uint_type ? printf("uint") : 0;
}

int				main(void)
{
	int			**array;
	// int			i;

	array = (info_arr_set2()).arr;
	// i = 0;
	// while (array[rt_camera][i] >= 0)
	// {
	// 	type_enum_print(array[rt_camera][i]);
	// 	printf("\n");
	// 	i++;
	// }
	printf("%d\n", array[rt_camera][c_ID]);
}

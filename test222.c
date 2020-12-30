/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test222.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:25:10 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/30 17:19:47 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

int			rt_elemlen(char *elem)
{
	int		i;

	i = 0;
	while (elem[i] >= 0)
		i++;
	return (i);
}

char	**info_arr_dup(char **data)
{
	char	**info_arr;
	int		elemlen;
	int		i;

	if (!(info_arr = malloc(sizeof(char *) * (rt_elems_num + 1))))
		return (NULL);
	i = 0;
	while (i < rt_elems_num)
	{
		elemlen = rt_elemlen(data[i]);
		if (!(info_arr[i] = malloc(elemlen + 1)))
			break ;
		ft_memmove(info_arr[i], data[i], elemlen + 1);
		i++;
	}
	if (i != rt_elems_num)
	{
		while (i >= 0)
			free(info_arr[i--]);
		free(info_arr);
		return (NULL);
	}
	info_arr[i] = NULL;
	return (info_arr);
}

char		**info_arr_set2(void)
{
	char			**info_arr;
	char			**data;

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
		(char[]){rt_rotation, ID_type, angle_type, angle_type, angle_type, -1}
	};
	info_arr = info_arr_dup(data);
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
		printf("not a valid type");
}
void	elem_enum_print(int	type)
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
		printf("not a valid type");
}

void		free_info_arr(char ***info)
{

	int		i;

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

int			main(void)
{
	int		i, j;
	char	**array;

	if (!(array = info_arr_set2()))
		return (-1);
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
		printf("\n");
	}
}

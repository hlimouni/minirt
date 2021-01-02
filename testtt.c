/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:47:54 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/02 18:03:51 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

// void	rt_scene_init(t_scene *scene)
// {
// 	scene->res = NULL;
// 	scene->amb = NULL;
// 	scene->cams = NULL;
// 	scene->lights = NULL;
// 	scene->objs = NULL;
// }

// t_sphere	rt_sphere_create(char **splitd_line)
// {
// 	t_sphere	sphere;

// 	sphere.o = str_to_vect(splitd_line[sp_center]);
// 	sphere.r = str_tof(splitd_line[sp_diameter]);
// 	sphere.r /= 2;
// 	sphere.color = str_to_rgbint(splitd_line[sp_color]);
// 	return (sphere);
// }

// int	rt_square_push(char   **splitd_line, t_scene *scene)
// {
//     t_square    *square;
// 	t_list		*new_node;

// 	if (!(square = (t_square *)malloc(sizeof(t_square))))
// 		return (0);
//     square->origin = str_to_vect(splitd_line[sq_position]);
//     square->normal = str_to_vect(splitd_line[sq_normal]);
// 	square->normal = vect_unit(square.normal);
//     square->side = str_tof(splitd_line[sq_side]);
//     square->color = str_to_rgbint(splitd_line[sq_color]);
// 	new_node = ft_lstnew((void *)square);
// 	new_node->element = rt_square;
// 	ft_lstadd_front(&(scene->objs), new_node);
// 	return (1);
// }

// /*
// ** The content is allocated so as the new node
// */

// void	element_square_create(const char *str, t_scene *scene)
// {
// 	char	**arr;
// 	int		i;
// 	void	*ptr;
// 	t_list	*new_node;
	
// 	arr = ft_split(str, ' ');
// 	ptr = rt_square_create(arr);
// 	rt_scene_initialize(scene);
// 	scene->objs = ft_lstnew(ptr);
// }

void	arr_init(int arr[3][2])
{
	int i,j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 2)
		{
			arr[i][j] = -1;
			j++;
		}
		i++;
	}
}

int		main(void)
{
	int		arr[3][2];
	int		i,j;

	arr_init(arr);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 2)
		{
			printf("%d", arr[i][j]);
			// if (j != 1)
				printf(" ");
			j++;
		}
			printf("\n");
		i++;
	}
	printf("%d\n", (-1 * ft_atoi("-3") && ft_atoi("-1235")));
	return (0);
}
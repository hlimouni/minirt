/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:05:18 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/29 10:43:07 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	scene_init(t_scene *scene)
{
	scene->res = NULL;
	scene->amb = NULL;
	scene->cams = NULL;
	scene->lights = NULL;
	scene->objs = NULL;
}

static void	info_arr_init(int arr[rt_elems_num + 1][max_params])
{
	int		i;
	int		j;

	i = 0;
	while (i < rt_elems_num + 1)
	{
		j = 0;
		while (j < max_params)
		{
			arr[i][j] = NEGATIVE_VALUE;
			j++;
		}
		i++;
	}
}

void	rt_data_init(t_scene *scene, int arr[rt_elems_num + 1][max_params])
{
	scene_init(scene);
	info_arr_init(arr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:05:18 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/31 08:20:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->res = NULL;
	scene->amb = NULL;
	scene->cams = NULL;
	scene->lights = NULL;
	scene->objs = NULL;
}

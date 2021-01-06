/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_res_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:54:43 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 12:54:51 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_res_push(char **splitd_line, t_scene *scene)
{
	t_resolution		*resolution;

	if (scene->res)
		return (-1);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (0);
	ft_strtoi(splitd_line[res_height], &(resolution->height));
	ft_strtoi(splitd_line[res_width], &(resolution->width));
	scene->res = resolution;
	return (1);
}

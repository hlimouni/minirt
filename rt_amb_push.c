/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_amb_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:54:06 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 12:54:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_amb_push(char **splitd_line, t_scene *scene)
{
	t_amb		*amb;

	if (scene->amb)
		return (-1);
	if (!(amb = malloc(sizeof(t_amb))))
		return (0);
	amb->intensity = str_tof(splitd_line[amb_ratio]);
	amb->color = str_to_rgbint(splitd_line[amb_color]);
	scene->amb = amb;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_ID.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:42:50 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/08 07:38:54 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_str_ID(char *str)
{
	if (!str)
		return (NEGATIVE_VALUE);
	if (ft_strcmp(str, "sq") == 0)
		return (rt_square);
	if (ft_strcmp(str, "A") == 0)
		return (rt_ambiant);
	if (ft_strcmp(str, "R") == 0)
		return (rt_resolution);
	if (ft_strcmp(str, "c") == 0)
		return (rt_camera);
	if (ft_strcmp(str, "tr") == 0)
		return (rt_triangle);
	if (ft_strcmp(str, "l") == 0)
		return (rt_light);
	if (ft_strcmp(str, "pl") == 0)
		return (rt_plane);
	if (ft_strcmp(str, "sp") == 0)
		return (rt_sphere);
	if (ft_strcmp(str, "cy") == 0)
		return (rt_cylinder);
	if (ft_strcmp(str, "tran") == 0)
		return (rt_translation);
	if (ft_strcmp(str, "rot") == 0)
		return (rt_rotation);
	return (NEGATIVE_VALUE);
}
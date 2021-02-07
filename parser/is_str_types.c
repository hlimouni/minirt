/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:25:08 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 18:15:25 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		is_str_id(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "sq") || !ft_strcmp(str, "R") ||
			!ft_strcmp(str, "c") || !ft_strcmp(str, "tr") ||
			!ft_strcmp(str, "l") || !ft_strcmp(str, "pl")
			|| !ft_strcmp(str, "sp") || !ft_strcmp(str, "cy") ||
			!ft_strcmp(str, "tran") || !ft_strcmp(str, "rot"))
		return (1);
	return (0);
}

int		is_str_ratio(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0 && str_tof(str) <= 1);
}

int		is_str_ufloat(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0);
}

int		is_str_euler(char *str)
{
	return (is_str_float(str) && str_tof(str) >= -180. && str_tof(str) <= 180.);
}

int		is_str_angle(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0 && str_tof(str) <= 180);
}

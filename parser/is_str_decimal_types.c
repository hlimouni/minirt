/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_decimal_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:25:08 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/26 19:29:35 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		is_str_theta(char *str)
{
	return (is_str_float(str) && str_tof(str) >= -90. && str_tof(str) <= 90.);
}

int		is_str_ratio(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0 && str_tof(str) <= 1);
}

int		is_str_ufloat(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0);
}

int		is_str_phi(char *str)
{
	return (is_str_float(str) && str_tof(str) >= -180. && str_tof(str) <= 180.);
}

int		is_str_angle(char *str)
{
	return (is_str_float(str) && str_tof(str) >= 0 && str_tof(str) <= 180);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:01:03 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/19 20:57:14 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_str(char *str, int type)
{
	t_typechecker	typechecker_arr[rt_types_num];
	
	if (type >= rt_types_num || type < 0)
		return (-1);
	typechecker_arr[rt_ID] = &is_str_ID;
	typechecker_arr[rt_vector] = &is_str_vector;
	typechecker_arr[rt_decimal] = &is_str_float;
	typechecker_arr[rt_udecimal] = &is_str_ufloat;
	typechecker_arr[rt_rgb] = &is_str_rgb;
	typechecker_arr[rt_ratio] = &is_str_ratio;
	typechecker_arr[rt_angle] = &is_str_angle;
	typechecker_arr[rt_positive_int] = &is_str_uint;
	return (typechecker_arr[rt_type](str));
}
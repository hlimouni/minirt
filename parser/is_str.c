/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:01:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 17:26:38 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_str(char *str, int type)
{
	t_typechecker	typechecker_arr[rt_types_num];
	
	if (type >= rt_types_num || type < 0)
		return (NEGATIVE_VALUE);
	typechecker_arr[ID_type] = is_str_ID;
	typechecker_arr[vector_type] = is_str_vect;
	typechecker_arr[decimal_type] = is_str_float;
	typechecker_arr[udecimal_type] = is_str_ufloat;
	typechecker_arr[rgb_type] = is_str_rgb;
	typechecker_arr[ratio_type] = is_str_ratio;
	typechecker_arr[angle_type] = is_str_angle;
	typechecker_arr[uint_type] = is_str_uint;
	typechecker_arr[yaw_type] = is_str_yaw;
	typechecker_arr[pitch_type] = is_str_pitch;
	typechecker_arr[roll_type] = is_str_pitch;
	return (typechecker_arr[type](str));
}
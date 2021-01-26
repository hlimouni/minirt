/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:01:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/26 19:31:01 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		is_str_uint(char *str)
{
	size_t		i;

	if (!str)
		return (0);
	i = 0;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (i);
	return (0);
}

int			is_str_rgb(char *str)
{
	int		i;
	char	**arr;
	char	*trimd_str;
	char	comma_count;
	int		color;

	if (!str)
		return (0);
	if ((comma_count = ft_strchar_count(str, ',')) != 2)
		return (0);
	if (!(trimd_str = ft_strtrim(str, ",")))
		return (-1);
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null((void *)&trimd_str);
		return (0);
	}
	ft_free_null((void *)&trimd_str);
	if (!(arr = ft_split(str, ',')))
		return (-1);
	i = 0;
	while (is_str_uint(arr[i]) && !ft_strtoi(arr[i], &color) && color <= 0xFF)
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}

int			is_str_vect(char *str)
{
	int		i;
	char	**arr;
	char	*trimd_str;
	char	comma_count;

	if (!str)
		return (0);
	if ((comma_count = ft_strchar_count(str, ',')) != 2)
		return (0);
	if (!(trimd_str = ft_strtrim(str, ",")))
		return (-1);
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null((void **)&trimd_str);
		return (0);
	}
	ft_free_null((void **)&trimd_str);
	if (!(arr = ft_split(str, ',')))
		return (-1);
	i = 0;
	while (is_str_float(arr[i]))
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}

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
	typechecker_arr[phi_type] = is_str_phi;
	typechecker_arr[theta_type] = is_str_theta;
	typechecker_arr[psi_type] = is_str_theta;
	return (typechecker_arr[type](str));
}
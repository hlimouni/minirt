/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:58:57 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 15:03:21 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		str_get_sign(char *str, int *index)
{
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		(*index)++;
	}
	if (*str == '+')
	{
		sign = 1;
		(*index)++;
	}
	return (sign);
}

double	str_tof(char *str)
{
	double	res;
	float	sign;
	int		i;
	int		frac_pt;

	i = 0;
	res = 0;
	frac_pt = NEGATIVE_VALUE;
	sign = str_get_sign(str, &i);
	while (str[i])
	{
		if (str[i] == '.')
		{
			frac_pt = ++i;
			continue ;
		}
		res = res * 10 + str[i++] - '0';
	}
	frac_pt >= 0 ? res = res * __exp10(frac_pt - (int)ft_strlen(str)) : 0;
	if (res >= A_BIG_VALUE)
		return (sign < 0 ? -INFINITY : INFINITY);
	return (sign < 0 ? -res : res);
}

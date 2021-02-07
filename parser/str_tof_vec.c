/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tof_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:58:57 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 18:25:35 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	str_get_sign(char *str, int *index)
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

double		str_tof(char *str)
{
	double	res;
	float	sign;
	int		i;
	int		frac_pt;

	i = 0;
	res = 0;
	frac_pt = -1;
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
	frac_pt >= 0 ? res = res * pow(10, frac_pt - (int)ft_strlen(str)) : 0;
	if (res >= A_BIG_VALUE)
		return (sign < 0 ? -A_BIG_VALUE : A_BIG_VALUE);
	return (sign < 0 ? -res : res);
}

t_vect		str_to_vect(char *str)
{
	t_vect	vect;
	char	**arr;

	arr = ft_split(str, ',');
	vect.x = str_tof(arr[0]);
	vect.y = str_tof(arr[1]);
	vect.z = str_tof(arr[2]);
	free_2d_array(&arr);
	return (vect);
}

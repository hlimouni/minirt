/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:55:51 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/11 17:10:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "minirt.h"

float   str_to_float(char *str)
{
	char    **arr;
	float	f;
	char	*prec;

	arr = ft_split(str, '.');
	f = (float)ft_atoi(*arr);
	if ((prec = arr[1]))
		f = f + (float)ft_atoi(prec) / pow(10, (float)ft_strlen(prec));
	free_2d_array(arr);
	return (f);
}
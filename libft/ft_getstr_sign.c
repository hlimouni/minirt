/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:13:20 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 17:28:35 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_getstr_sign(char *str, int *index)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:59:15 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/02 18:59:38 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_struint(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (i);
	return (0);
}
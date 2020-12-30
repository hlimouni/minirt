/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:57:18 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/30 17:59:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_elemlen(char	*element)
{
	int	i;

	i = 0;
	while (element[i] >= 0)
		i++;
	return (i);
}
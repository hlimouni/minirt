/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putscount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:52:06 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/25 00:41:28 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putss(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count += ft_putccount(*str);
		str++;
	}
	return (count);
}

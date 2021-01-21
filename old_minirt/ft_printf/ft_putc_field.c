/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:01:13 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/24 21:35:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc_field(char c, int *field)
{
	int		count;

	count = 0;
	if (field[flag] == '0')
	{
		count += ft_putnchar('0', field[width] - 1);
		count += ft_putccount(c);
	}
	else if (field[flag] < 0)
	{
		count += ft_putnchar(' ', field[width] - 1);
		count += ft_putccount(c);
	}
	else if (field[flag] == '-')
	{
		count += ft_putccount(c);
		count += ft_putnchar(' ', field[width] - 1);
	}
	return (count);
}

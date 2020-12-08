/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:17:40 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/26 11:25:29 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnss(char *str, size_t max)
{
	size_t	len;

	len = 0;
	while (len < max)
	{
		if (*str == '\0')
			break ;
		len += ft_putccount(*str);
		str++;
	}
	return (len);
}

static int	diff(int x, int y)
{
	return (x > y ? x - y : 0);
}

int			ft_puts_field(char *str, int *field)
{
	int	count;
	int	len;

	count = 0;
	!str ? str = "(null)" : 0;
	field[precision] < 0 ? (len = ft_strlen(str)) :
		(len = ft_strnlen(str, field[precision]));
	if (field[flag] == '0')
	{
		count += ft_putnchar('0', diff(field[width], len));
		count += ft_putnss(str, len);
	}
	else if (field[flag] < 0)
	{
		count += ft_putnchar(' ', diff(field[width], len));
		count += ft_putnss(str, len);
	}
	if (field[flag] == '-')
	{
		count += ft_putnss(str, len);
		count += ft_putnchar(' ', diff(field[width], count));
	}
	return (count);
}

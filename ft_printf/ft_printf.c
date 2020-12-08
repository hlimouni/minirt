/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:47:28 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/29 10:35:07 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_vprintf_ints(va_list ap, int field[], int *ret)
{
	if (field[type] == 'd' || field[type] == 'i')
		*ret += ft_putnbr_field(va_arg(ap, int), field);
	else if (field[type] == 'u')
		*ret += ft_putu_field(va_arg(ap, unsigned int), field);
	else if (field[type] == 'x' || field[type] == 'X')
		*ret += ft_puthex_field(va_arg(ap, int), field);
	else if (field[type] == 'c')
		*ret += ft_putc_field(va_arg(ap, int), field);
}

static void	ft_vprintf_pointers(va_list ap, int field[], int *ret)
{
	if (field[type] == 's')
		*ret += ft_puts_field(va_arg(ap, char *), field);
	else if (field[type] == 'p')
		*ret += ft_putp_field(va_arg(ap, void *), field);
}

int			ft_printf(const char *fmt, ...)
{
	int		field[4];
	int		ret;
	va_list ap;

	ret = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = ft_tokenizer((char *)++fmt, field, ap);
			if (field[type] == '%')
				ret += ft_putc_field('%', field);
			else if (field[type] == 's' || field[type] == 'p')
				ft_vprintf_pointers(ap, field, &ret);
			else if (ft_strchr("diucxX", field[type]))
				ft_vprintf_ints(ap, field, &ret);
		}
		else
			ret += ft_putccount(*fmt++);
	}
	va_end(ap);
	return (ret);
}

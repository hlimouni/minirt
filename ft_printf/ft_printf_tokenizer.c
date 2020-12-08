/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:25:08 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/29 10:36:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width_toi(char **str)
{
	int nb;

	nb = ft_atoi(*str);
	*str += ft_nbrlen(nb);
	return (nb);
}

static int	ft_prec(char **str, int field[])
{
	while (**str == '0')
		(*str)++;
	if (**str == '-')
		return (0);
	if (ft_isdigit(**str))
	{
		field[precision] = ft_atoi(*str);
		*str += ft_nbrlen(field[precision]);
	}
	return (1);
}

static int	ft_type(char **str, int field[])
{
	if (**str && ft_strchr("cspdiuxX%", **str))
	{
		field[type] = **str;
		(*str)++;
		return (0);
	}
	else
		return (1);
}

static void	ft_asterisk(int index, char **str, int field[], va_list ap)
{
	int		arg;

	arg = va_arg(ap, int);
	if (arg < 0 && index == width)
	{
		field[flag] = '-';
		field[index] = -1 * arg;
	}
	else
		field[index] = arg;
	(*str)++;
}

char		*ft_tokenizer(char *str, int *field, va_list ap)
{
	ft_memset(field, 0xff, sizeof(int) * 4);
	while (*str && ft_strchr(FORMAT, *str))
	{
		(*str == '*') ? ft_asterisk(width, &str, field, ap) : 0;
		if (*str == '-' || *str == '0')
			(field[flag] == '-' ? *str++ : (field[flag] = *str++));
		else if (ft_isdigit(*str))
			field[width] = ft_width_toi(&str);
		if (*str == '.')
		{
			str++;
			field[precision] = 0;
			(*str == '*') ? ft_asterisk(precision, &str, field, ap) : 0;
			if (ft_isdigit(*str))
			{
				if (!ft_prec(&str, field))
					continue ;
			}
		}
		if (!ft_type(&str, field))
			break ;
	}
	return (str);
}

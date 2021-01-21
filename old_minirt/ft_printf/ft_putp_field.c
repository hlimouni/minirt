/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:25:33 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/29 10:40:42 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	diff(int x, int y)
{
	return (x > y ? x - y : 0);
}

static int	ft_longlen(long nb)
{
	int				len;
	unsigned long	nbr;

	len = 1;
	nbr = (unsigned long)nb;
	while (nbr / 16)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static int	ft_putp(long nb)
{
	char			*arr;
	int				i;
	int				digit;
	unsigned long	nbr;

	i = ft_longlen(nb);
	nbr = (unsigned long)nb;
	if (!(arr = (char*)ft_calloc(sizeof(char), i + 1)))
		return (-1);
	while (i > 0)
	{
		digit = nbr % 16;
		if (digit < 10)
			arr[i - 1] = '0' + digit;
		else if (digit < 16)
			arr[i - 1] = 'a' + digit - 10;
		nbr /= 16;
		i--;
	}
	i = ft_putss(arr);
	free(arr);
	return (i);
}

static int	ft_putp_zeros(long nbr, int zeros, int field[])
{
	int		cnt;

	cnt = ft_putss("0x");
	cnt += ft_putnchar('0', zeros);
	if (nbr || field[precision])
		cnt += ft_putp(nbr);
	return (cnt);
}

int			ft_putp_field(void *ptr, int *field)
{
	int		cnt;
	int		zeros;
	int		prec_nbr;
	long	nbr;

	cnt = 0;
	nbr = (long)ptr;
	if (field[flag] == '0' && field[precision] < 0)
		cnt += ft_putp_zeros(nbr, diff(field[width],
											(2 + ft_longlen(nbr))), field);
	else if (field[flag] < 0 || (field[flag] == '0' && field[precision] >= 0))
	{
		zeros = diff(field[precision], ft_longlen(nbr));
		(nbr || field[precision]) ? prec_nbr = zeros + ft_longlen(nbr)
			: (prec_nbr = 0);
		cnt += ft_putnchar(' ', diff(field[width], 2 + prec_nbr));
		cnt += ft_putp_zeros(nbr, zeros, field);
	}
	if (field[flag] == '-')
	{
		zeros = diff(field[precision], ft_longlen(nbr));
		cnt += ft_putp_zeros(nbr, zeros, field);
		cnt += ft_putnchar(' ', diff(field[width], cnt));
	}
	return (cnt);
}

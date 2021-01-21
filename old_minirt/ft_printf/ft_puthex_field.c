/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:40:25 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/28 23:03:21 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_diff(int x, int y)
{
	return (x > y ? x - y : 0);
}

static char	*ft_itoa_hex(unsigned int nbr, char c)
{
	char	*arr;
	int		i;
	int		digit;

	i = ft_hexlen(nbr);
	if (!(arr = (char*)ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	while (i > 0)
	{
		digit = nbr % 16;
		if (digit < 10)
			arr[i - 1] = '0' + digit;
		else if (digit < 16)
		{
			if (c == 'x')
				arr[i - 1] = 'a' + digit - 10;
			if (c == 'X')
				arr[i - 1] = 'A' + digit - 10;
		}
		nbr /= 16;
		i--;
	}
	return (arr);
}

static int	ft_putxcount(int nbr, char c)
{
	char	*str;
	int		count;

	if (!(str = ft_itoa_hex(nbr, c)))
		return (-1);
	count = ft_putss(str);
	free(str);
	return (count);
}

static int	ft_putx_zeros(int nbr, int zeros, int field[])
{
	int	cnt;

	cnt = 0;
	cnt += ft_putnchar('0', zeros);
	if (nbr || field[precision])
		cnt += ft_putxcount(nbr, field[type]);
	return (cnt);
}

int			ft_puthex_field(int nbr, int *field)
{
	int cnt;
	int zeros;
	int	prec_nbr;

	cnt = 0;
	if (field[flag] == '0' && field[precision] < 0)
		cnt += ft_putx_zeros(nbr, ft_diff(field[width], ft_hexlen(nbr)), field);
	else if (field[flag] < 0 || (field[flag] == '0' && field[precision] >= 0))
	{
		zeros = ft_diff(field[precision], ft_hexlen(nbr));
		(nbr || field[precision]) ? prec_nbr = zeros + ft_hexlen(nbr)
			: (prec_nbr = 0);
		cnt += ft_putnchar(' ', ft_diff(field[width], prec_nbr));
		cnt += ft_putx_zeros(nbr, zeros, field);
	}
	if (field[flag] == '-')
	{
		zeros = ft_diff(field[precision], ft_hexlen(nbr));
		cnt += ft_putx_zeros(nbr, zeros, field);
		cnt += ft_putnchar(' ', ft_diff(field[width], cnt));
	}
	return (cnt);
}

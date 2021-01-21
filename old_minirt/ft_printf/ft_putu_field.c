/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:17:28 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/28 22:39:07 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unlen(unsigned int nb)
{
	int		len;

	len = 1;
	while (nb / 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static int	ft_putu(unsigned int nbr)
{
	char	*arr;
	int		i;

	i = ft_unlen(nbr);
	if (!(arr = (char*)ft_calloc(sizeof(char), i + 1)))
		return (-1);
	while (i > 0)
	{
		arr[i - 1] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	i = ft_putss(arr);
	free(arr);
	return (i);
}

static int	ft_diff(int x, int y)
{
	return (x > y ? x - y : 0);
}

static int	ft_putu_zeros(int nbr, int zeros, int field[])
{
	int	cnt;

	cnt = 0;
	cnt += ft_putnchar('0', zeros);
	if (nbr || field[precision])
		cnt += ft_putu(nbr);
	return (cnt);
}

int			ft_putu_field(unsigned int nbr, int *field)
{
	int cnt;
	int zeros;
	int	prec_nbr;

	cnt = 0;
	if (field[flag] == '0' && field[precision] < 0)
		cnt += ft_putu_zeros(nbr, ft_diff(field[width], ft_unlen(nbr)), field);
	else if (field[flag] < 0 || (field[flag] == '0' && field[precision] >= 0))
	{
		zeros = ft_diff(field[precision], ft_unlen(nbr));
		(nbr || field[precision]) ? prec_nbr = zeros + ft_unlen(nbr)
			: (prec_nbr = 0);
		cnt += ft_putnchar(' ', ft_diff(field[width], prec_nbr));
		cnt += ft_putu_zeros(nbr, zeros, field);
	}
	if (field[flag] == '-')
	{
		zeros = ft_diff(field[precision], ft_unlen(nbr));
		cnt += ft_putu_zeros(nbr, zeros, field);
		cnt += ft_putnchar(' ', ft_diff(field[width], cnt));
	}
	return (cnt);
}

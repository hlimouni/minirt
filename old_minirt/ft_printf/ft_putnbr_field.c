/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:53:03 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/26 13:07:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nblen(int nb)
{
	return (nb < 0 ? ft_nbrlen(nb) - 1 : ft_nbrlen(nb));
}

static int	ft_diff(int x, int y)
{
	return (x > y ? x - y : 0);
}

static int	ft_putd_zeros(int nbr, int zeros, int field[])
{
	int	cnt;

	cnt = 0;
	if (nbr < 0)
		cnt += ft_putccount('-');
	cnt += ft_putnchar('0', zeros);
	if (nbr || field[precision])
		cnt += ft_putdcount(nbr > 0 ? nbr : -nbr);
	return (cnt);
}

int			ft_putnbr_field(int nbr, int *field)
{
	int	cnt;
	int	zeros;
	int prec_nbr;

	cnt = 0;
	if (field[flag] == '0' && field[precision] < 0)
		cnt += ft_putd_zeros(nbr, ft_diff(field[width], ft_nbrlen(nbr)), field);
	else if (field[flag] < 0 || (field[flag] == '0' && field[precision] >= 0))
	{
		zeros = ft_diff(field[precision], ft_nblen(nbr));
		(nbr || field[precision]) ? prec_nbr = zeros + ft_nbrlen(nbr)
			: (prec_nbr = 0);
		cnt += ft_putnchar(' ', ft_diff(field[width], prec_nbr));
		cnt += ft_putd_zeros(nbr, zeros, field);
	}
	if (field[flag] == '-')
	{
		zeros = ft_diff(field[precision], ft_nblen(nbr));
		cnt += ft_putd_zeros(nbr, zeros, field);
		cnt += ft_putnchar(' ', ft_diff(field[width], cnt));
	}
	return (cnt);
}

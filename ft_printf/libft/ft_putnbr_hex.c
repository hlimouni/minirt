/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:51:18 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/09 14:45:44 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(int nb)
{
	unsigned int	nbr;

	nbr = (unsigned int)nb;
	if (nbr < 10)
		ft_putchar('0' + nbr);
	else if (nbr < 16)
		ft_putchar('a' + nbr - 10);
	else
	{
		ft_putnbr_hex(nbr / 16);
		ft_putnbr_hex(nbr % 16);
	}
}

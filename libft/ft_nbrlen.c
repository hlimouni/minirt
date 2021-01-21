/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:48:56 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/25 21:29:00 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int nbr)
{
	int		len;
	long	nb;

	len = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -1 * nb;
		len++;
	}
	while (nb / 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

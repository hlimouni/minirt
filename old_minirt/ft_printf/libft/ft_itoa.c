/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:44:30 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/19 15:51:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nb)
{
	char	*arr;
	int		i;
	long	nbr;

	nbr = nb;
	i = ft_nbrlen(nbr);
	if (!(arr = (char*)ft_calloc(sizeof(char), ft_nbrlen(nbr) + 1)))
		return (NULL);
	if (nb < 0)
		nbr = -1 * nbr;
	while (i > 0)
	{
		arr[i - 1] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	if (nb < 0)
		arr[0] = '-';
	return (arr);
}

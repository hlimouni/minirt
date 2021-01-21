/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:46:10 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/25 00:17:22 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(int nb)
{
	int				len;
	unsigned int	nbr;

	len = 1;
	nbr = (unsigned int)nb;
	while (nbr / 16)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

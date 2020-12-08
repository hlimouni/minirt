/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:00:32 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/26 09:19:02 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putdcount(int nbr)
{
	char	*str;
	int		count;

	if (!(str = ft_itoa(nbr)))
		return (-1);
	if (nbr == -2147483648)
		count = ft_putss(str + 1);
	else
		count = ft_putss(str);
	free(str);
	return (count);
}

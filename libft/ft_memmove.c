/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:09:18 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/12 23:22:29 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	void	*ret;

	ret = dest;
	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = len;
		while (i > 0)
		{
			((char*)dest)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	return (ret);
}

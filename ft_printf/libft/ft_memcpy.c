/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:14:15 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/17 22:19:44 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*ret;

	if (!dest && !src)
		return (NULL);
	ret = dest;
	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((const char*)src)[i];
		i++;
	}
	return (ret);
}

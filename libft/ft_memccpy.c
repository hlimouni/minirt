/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:19:20 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/17 22:40:58 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	size_t				i;
	char				*dst;
	const unsigned char	*src;

	dst = (char *)to;
	src = (const unsigned char*)from;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			break ;
		if (src[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}

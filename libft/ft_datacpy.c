/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datacpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:03:56 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/30 11:17:18 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_datacpy(void *to, const void *from, int c, size_t n)
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
			return (i);
		i++;
	}
	return (i);
}

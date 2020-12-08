/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:29:45 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/12 22:48:24 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t				i;
	const unsigned char	*char_ptr;
	unsigned char		ch;

	ch = (unsigned char)c;
	char_ptr = (const unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (char_ptr[i] == ch)
			return ((void*)(&char_ptr[i]));
		i++;
	}
	return (NULL);
}

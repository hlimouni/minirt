/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:11:35 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/17 21:10:31 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dst, char const *src)
{
	char	*str;
	size_t	dstlen;
	size_t	srclen;

	if (!dst || !src)
		return (NULL);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	str = (char*)malloc(sizeof(char) * (dstlen + srclen + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, dst, dstlen + 1);
	ft_strlcat(str, src, srclen + dstlen + 1);
	return (str);
}

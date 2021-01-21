/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:06:57 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/20 19:09:38 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*haystack;
	char	*needle;
	size_t	needlelen;

	haystack = (char*)s1;
	needle = (char*)s2;
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return (haystack);
	while (*haystack && n >= needlelen)
	{
		if (ft_strncmp(haystack, needle, needlelen) == 0)
			return (haystack);
		haystack++;
		n--;
	}
	return (NULL);
}

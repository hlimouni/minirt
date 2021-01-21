/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:11:35 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/22 21:05:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dst, char const *src)
{
	char	*str;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*dst)
		str[i++] = *dst++;
	while (*src)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:59:30 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/15 15:03:31 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	c = (char)c;
	while (1)
	{
		if (*str == c)
			return ((char*)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
}

char	*ft_strdup(const char *str)
{
	char			*ptr;
	unsigned int	i;

	ptr = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *dst, char const *src)
{
	char		*str;
	size_t		i;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	char		*src;
	size_t		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	src = (char*)s + start;
	i = 0;
	while (i < len && src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:46:33 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/20 19:07:09 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(str, '\0'));
	ptr = NULL;
	while (ft_strchr(str, c))
	{
		ptr = ft_strchr(str, c);
		str = ptr + 1;
	}
	return ((char*)ptr);
}

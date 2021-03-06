/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:28:46 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/08 10:41:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*front;
	char	*back;
	char	*new;

	if (!s || !set)
		return (NULL);
	front = (char*)s;
	back = (char*)s + ft_strlen(s) - 1;
	while (front <= back)
	{
		if (ft_strchr(set, *front) == NULL && ft_strchr(set, *back) == NULL)
			break ;
		if (ft_strchr(set, *front))
			front++;
		if (ft_strchr(set, *back))
			back--;
	}
	if (front > back)
		return (ft_strdup(""));
	new = ft_substr(front, 0, back - front + 1);
	return (new);
}

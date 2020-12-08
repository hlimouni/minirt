/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:57:19 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/08 13:38:02 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchar_count(char *str, int c)
{
	int		count;
	char	*found;

	if (!str)
		return (0);
	count = 0;
	while ((found = ft_strchr(str, c)))
	{
		count++;
		if (*found == '\0')
			break ;
		str = ++found;
	}
	return (count);
}

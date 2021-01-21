/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:29 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/08 11:40:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwords(char const *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		while (*str != c && *str)
			str++;
		if (*str == c || *str == '\0')
			count++;
	}
	return (count);
}

static int	ft_wordlen(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char	**ft_freeprev(int index, char ***tab)
{
	int		i;

	i = 0;
	while (i < index)
		free((*tab)[i++]);
	free(*tab);
	*tab = NULL;
	return (*tab);
}

char		**ft_split(char const *str, char c)
{
	char	**output;
	int		wlen;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	if (!(output = (char **)malloc(sizeof(char *) * (ft_cwords(str, c) + 1))))
		return (NULL);
	while (*str)
	{
		if (*str == c)
			str++;
		else if (*str != c && *str)
		{
			wlen = ft_wordlen(str, c);
			if (!(output[i++] = ft_substr(str, 0, wlen)))
				return (ft_freeprev(i, &output));
			str += wlen;
		}
	}
	output[i] = 0;
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:04:02 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:46:40 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		is_strint(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) > 1)
		i++;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (i);
	return (0);
}

/*
** is_strint and is_strsign both check if string is integer but:
** is_strint returns FALSE when the input values are "-" or "+"
** is_strsign returns them as true
*/

static int		is_strsign(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (i);
	return (0);
}

static int		is_strnint(char *str, size_t n)
{
	int		i;
	int		snlen;

	if (!str)
		return (0);	
	i = 0;
	snlen = ft_strnlen(str, n);
	if ((str[i] == '-' || str[i] == '+') && snlen > 1)
		i++;
	while (ft_isdigit(str[i]) && i < snlen)
		i++;
	if (snlen == i)
		return (i);
	return (0);
}

static int		is_strnsign(char *str, size_t n)
{
	int		i;
	int		snlen;
	
	if (!str)
		return (0);
	i = 0;
	snlen = ft_strnlen(str, n);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && i < snlen)
		i++;
	if (snlen == i)
		return (i);
	return (0);
}

/*
** is_str_float tests if the given string can be defined as a float or not
** it checks for the precison '.' so it exists only once in the string and
** than tests for different cases of '.' placement: (end, middle, front).
*/

int		is_str_float(char *str)
{
	int		points;
	char	*prec_pt;
	int		slen;

	points = ft_strchar_count(str, '.');
	if (points == 0)
		return (is_strint(str));
	if (points == 1)
	{
		prec_pt = ft_strchr(str, '.');
		if (prec_pt == str)
			return (is_str_uint(prec_pt + 1));
		slen = ft_strlen(str);
		if (prec_pt == str + (slen - 1))
			return (is_strnint(str, slen - 1));
		return (is_strnsign(str, prec_pt - str) && is_str_uint(prec_pt + 1));
	}
	return (0);
}

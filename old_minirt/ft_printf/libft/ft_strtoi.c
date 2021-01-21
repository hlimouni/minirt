/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:08:53 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/09 10:28:09 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_overflow(long res, int *number, long max)
{
	if (res > max)
	{
		*number = 0x7fffffff;
		return (1);
	}
	return (0);
}

static int	is_underflow(long res, int *number, long abs_min)
{
	if (res > abs_min)
	{
		*number = (int)0x80000000;
		return (-1);
	}
	return (0);
}

static int	is_flow(long res, int *num, long lmts[], int sign)
{
	int		ret;

	if (sign > 0 && (ret = is_overflow(res, num, lmts[0])))
		return (ret);
	if (sign < 0 && (ret = is_underflow(res, num, lmts[1])))
		return (ret);
	return (0);
}

int			ft_strtoi(char *str, int *num)
{
	int		i;
	int		sn;
	long	res;
	int		ret;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sn = ft_getstr_sign(str + i, &i);
	while (ft_isdigit(str[i]))
	{
		if ((ret = is_flow(res, num, (long[]){MAXINT / 10, MININT / 10}, sn)))
			return (ret);
		res = res * 10;
		if ((ret = is_flow(res, num, (long[]){MAXINT - str[i] + '0',
										MININT - str[i] + '0'}, sn)))
			return (ret);
		res = res + str[i] - '0';
		i++;
	}
	*num = sn * res;
	return (0);
}

/*
**	int main(void)
**	{
**		char *str = "  	2147483646";
**		int number, ret;
**
**		ret = ft_strtoi(str, &number);
**		printf("str -> |%s| number == %d ret = %d\n", str, number, ret);
**	}
*/

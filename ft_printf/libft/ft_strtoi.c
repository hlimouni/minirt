/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:08:53 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 16:33:25 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		is_overflow(long res, int *number, long max)
{
	if (res > max)
	{
		*number = 0x7fffffff;
		return (1);
	}
	return (0);
}

static int		is_underflow(long res, int *number, long abs_min)
{
	if (res > abs_min)
	{
		*number = (int)0x80000000;
		return (-1);
	}
	return (0);
}

static int		check_flow(long res, int *num , long max, long abs_min , int sign)
{
	int	ret;

	if (sign > 0 && (ret = is_overflow(res, num, max)))
		return (ret);
	if (sign < 0 && (ret = is_underflow(res, num, abs_min)))
		return (ret);
	return (0);
}

int		ft_strtoi(char *str, int *num)
{
	int				i;
	int				sign;
	long			res;
	int				ret;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_getstr_sign(str + i, &i);
	while (ft_isdigit(str[i]))
	{
		if ((ret = check_flow(res, num, MAXINT / 10, MININT / 10, sign)))
			return (ret);
		res = res * 10;
		if ((ret = check_flow(res, num, MAXINT - str[i] - '0',
										MININT - str[i] - '0', sign)))
			return (ret);
		res = res + str[i] - '0';
		i++;
	}
	*num = sign * res;
	return (0);
}

// int main(void)
// {
// 	char *str = "  	-893900000000000000048alkjlflkj";
// 	int number, ret;

// 	ret = ft_strtoi(str, &number);
// 	printf("str -> |%s| number == %d ret = %d\n", str, number, ret);
// }
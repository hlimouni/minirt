/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:22:50 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/22 16:29:40 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define A_BIG_VALUE 1e14
#define NEGATIVE_VALUE -1

int		str_get_sign(char *str, int *index)
{
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		(*index)++;
	}
	if (*str == '+')
	{
		sign = 1;
		(*index)++;
	}
	return (sign);
}

double	str_tof(char *str)
{
	double	res;
	float	sign;
	int		i;
	int		frac_pt;

	i = 0;
	res = 0;
	frac_pt = NEGATIVE_VALUE;
	sign = str_get_sign(str, &i);
	while (str[i])
	{
		if (str[i] == '.')
		{
			frac_pt = ++i;
			continue ;
		}
		res = res * 10 + str[i++] - '0';
	}
	frac_pt >= 0 ? res = res * __exp10(frac_pt - (int)strlen(str)) : 0;
	if (res >= A_BIG_VALUE)
		return (sign < 0 ? -INFINITY : INFINITY);
	return (sign < 0 ? -res : res);
}
/*

int	main(void)
{
	int		exp;
	double	f, f1, f2;
	double	d;
	char	*str;
	f = 239.00211;
	frexp(f, &exp);
	printf("the float %f\n", f);
	printf("the exponent %d\n", exp);
	printf("the result %f\n", frexp(f, &exp));
	f = ldexp(frexp(f, &exp) ,exp);
	// printf("%lf\n", -340282346638528859811704183484516925441.000000);
	// printf("%d\n", signbit(-0.0));
	// f = 340282346638528859811704183484516925438.000000 + 1.0;
	// printf("%f\n", f); 
	str = "002.2012031";
	printf("f1 string is %s\n", str);
	printf("f1 == %.10lf\n", (f1 = str_tof(str)));
	//printf("f1 * negative power == %lf\n", f * __exp10(-6));
	//printf("%lf\n", (f2 = strfrac_tof("22")));
	//printf("%d\n", signbit(f1) );

	return 0;
}
*/

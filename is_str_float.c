/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:40:04 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/10 12:55:42 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "minirt.h"
#include <stdio.h>

int		is_strint(char *str)
{
	int		i;

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

int		is_strsign(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (i);
	return (0);
}

int		is_strnint(char *str, size_t n)
{
	int		i;
	int		snlen;
	
	i = 0;
	//  if (n == 0)
	//  	return (0);
	snlen = ft_strnlen(str, n);
	if ((str[i] == '-' || str[i] == '+') && snlen > 1)
		i++;
	while (ft_isdigit(str[i]) && i < snlen)
		i++;
	if (snlen == i)
		return (i);
	return (0);
}

int		is_strnsign(char *str, size_t n)
{
	int		i;
	int		snlen;
	
	i = 0;
	//  if (n == 0)
	//  	return (0);
	snlen = ft_strnlen(str, n);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && i < snlen)
		i++;
	if (snlen == i)
		return (i);
	return (0);
}

int		is_struint(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
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
			return (is_struint(prec_pt + 1));
		slen = ft_strlen(str);
		if (prec_pt == str + (slen - 1))
			return (is_strnint(str, slen - 1));
		return (is_strnsign(str, prec_pt - str) && is_struint(prec_pt + 1));
	}
	return (0);
}

t_vect	arr_to_vect(char *str)
{
	t_vect	vect;
	char	**arr;

	arr = ft_split(str, ',');
	vect.x = ft_atoi(arr[0]);
	vect.y = ft_atoi(arr[1]);
	vect.z = ft_atoi(arr[2]);
	free_2d_array(&arr);
	return (vect);
}
/*
int		is_3x3vect(char *str)
{
	char    **arr;
	int		i;
	int		j;
	int		dim;

	if (!str)
		return (0);
	if (!(arr = ft_split(str, ',')))
		return (0);
	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-' || arr[i][j] == '+')
			j++;
		while (ft_isdigit(arr[i][j++]))
		if (ft_strlen(arr[i]) == j)
			dim += i;
		i++;
	}
	if (dim == i && i == 3)
	{
		free_2d_array(&arr);
		// free(arr);
		// arr = NULL;
		return (dim);
	}
	else
	{
		free_2d_array(&arr);
		// free(arr);
		// arr = NULL;
		return (0);
	}
	
}
*/

int		main(void)
{
	// char	*str = "000233,523,111029";
	char	str1[] = "8";
	char	str2[] = "-0.";
	char	str3[] = "+.02";
	char	str4[] = "-.3";
	char	str5[] = "29382.-";
	char	str6[] = "-220.3330";
	char	str7[] = "+000.03230000001";
	char	str8[] = "-2332328.2220";
	printf("the string [%s] is float? == %s\n", str1, is_str_float(str1) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str2, is_str_float(str2) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str3, is_str_float(str3) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str4, is_str_float(str4) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str5, is_str_float(str5) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str6, is_str_float(str6) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str7, is_str_float(str7) ? "True" : "False");
	printf("the string [%s] is float? == %s\n", str8, is_str_float(str8) ? "True" : "False");
	printf("atoi test %d\n", atoi("--122"));
/*
	printf("%s ? == %d\n", "23233", is_strint("23233"));
	printf("%s ? == %d\n", "-2222", is_strint("-2222"));
	printf("%s ? == %d\n", "+2", is_strint("+2"));
	printf("%s ? == %d\n", "23.2", is_strint("23.2"));
	printf("%s ? == %d\n", "lkl", is_strint("lkl"));
	printf("%s ? == %d\n", "00023233", is_strint("00023233"));
	printf("%s ? == %d\n", "+", is_strint("-"));
	printf("%s ? == %d\n", "-", is_strint("+"));
*/
	// is_str_float("")
	/*
	printf("%d\n", is_3x3vect(str));
	if (is_3x3vect(str))
	{
		vector = arr_to_vect(str);
		printf("%f, %f, %f\n", vector.x, vector.y, vector.z);
	}
	*/
	return (0);
}

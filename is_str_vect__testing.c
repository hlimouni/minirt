/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:01:50 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/02 17:01:28 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_printf/libft/libft.h"

int		is_strint(char *str)
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

int		is_strsign(char *str)
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

int		is_strnint(char *str, size_t n)
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

int		is_strnsign(char *str, size_t n)
{
	int		i;
	int		snlen;
	
	i = 0;
	if (!str)
		return (0);
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

	if (!str)
		return (0);
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

	if (!str)
		return (0);
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

int     is_str_vect(char *str)
{
	int		i;
	char	**arr;
	char	*trimd_str;
	char	comma_count;
	
	if (!str)
		return (0);
	if ((comma_count = ft_strchar_count(str, ',')) != 2)
		return (0);
	trimd_str = ft_strtrim(str, ",");
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null(&(void *)trimd_str);
		return (0);
	}
	ft_free_null(&(void *)trimd_str);
	arr = ft_split(str, ',');
	i = 0;
	while (is_str_float(arr[i]))
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}

// float   str_to_float(char *str)
// {
// 	char    **arr;
// 	double	f;
// 	char	*prec;
// 	int		pwr;

// 	arr = ft_split(str, '.');
// 	f = ft_atoi(*arr);
// 	if ((prec = arr[1]))
// 	{
// 		pwr = -1 * ft_strlen(prec);
// 		f = fma((double)ft_atoi(prec), __exp10(pwr), f);
// 	}	// f = f + (double)ft_atoi(prec) / pow(10.0, ft_strlen(prec));
// 	free_2d_array(&arr);
// 	return (f);
// }

// float	str_int_part(char *str)
// {
// 	"23998239823";
// 	int		sign;
// 	float	f;
	
// 	f = 0.0;
// 	if (*str == '-')
// 	{
// 		f = -0.0;
// 		str++;
// 	}
// 	while
// }

int     is_str_rgb(char *str)
{
	int		i;
	char	**arr;
	char	*trimd_str;
	char	comma_count;
	int		color;

	if (!str)
		return (0);
	if ((comma_count = ft_strchar_count(str, ',')) != 2)
		return (0);
	trimd_str = ft_strtrim(str, ",");
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null((void *)&trimd_str);
		return (0);
	}
	ft_free_null((void *)&trimd_str);
	arr = ft_split(str, ',');
	i = 0;
	while (is_struint(arr[i]) && !ft_strtoi(arr[i], &color) && color <= 0xFF)
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}

int		main(void)
{
	char	str1[] = "000008";
	char	str2[] = "23.00003";
	char	str3[] = ".02";
	char	str4[] = "22208,-0.222,1.111110";
	char	str5[] = "+22.22";
	char	str6[] = "-2.";
	char	str7[] = "+000.03230000001";
	char	str8[] = "3232332328.22";
	printf("the string [%s] converted to float is  == %f\n", str1, str_to_float(str1));
	printf("the string [%s] converted to float is  == %f\n", str2, str_to_float(str2));
	printf("the string [%s] converted to float is  == %f\n", str3, str_to_float(str3));
	printf("the string [%s] converted to float is  == %f\n", str4, str_to_float(str4));
	printf("the string [%s] converted to float is  == %f\n", str5, str_to_float(str5));
	printf("the string [%s] converted to float is  == %f\n", str6, str_to_float(str6));
	printf("the string [%s] converted to float is  == %f\n", str7, str_to_float(str7));
	printf("the string [%s] converted to float is  == %f\n", str8, str_to_float(str8));
	printf("is atoi test %d\n", ft_atoi("0"));
	// printf("is the string [%s] a vector? == %s\n", str1, is_str_vect(str1) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str2, is_str_vect(str2) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str3, is_str_vect(str3) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str4, is_str_vect(str4) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str5, is_str_vect(str5) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str6, is_str_vect(str6) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str7, is_str_vect(str7) ? "True" : "False");
	// printf("is the string [%s] a vector? == %s\n", str8, is_str_vect(str8) ? "True" : "False");
	// printf("is atoi test %d\n", ft_atoi("0"));
	return (0);
}
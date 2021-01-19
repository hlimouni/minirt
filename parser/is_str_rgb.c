/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:20:36 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:53:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (!(trimd_str = ft_strtrim(str, ",")))
		return (-1);
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null((void *)&trimd_str);
		return (0);
	}
	ft_free_null((void *)&trimd_str);
	if (!(arr = ft_split(str, ',')))
		return (-1);
	i = 0;
	while (is_str_uint(arr[i]) && !ft_strtoi(arr[i], &color) && color <= 0xFF)
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}

// int		main(void)
// {
// 	char	str1[] = "00,00,08";
// 	char	str2[] = "-23,000,03";
// 	char	str3[] = "1,0,2";
// 	char	str4[] = "22208,22,1";
// 	char	str5[] = "+22,22,255";
// 	char	str6[] = "255,255,255";
// 	char	str7[] = "1,1,1";
// 	char	str8[] = "3232332328.22";
// 	// printf("the string [%s] converted to float is  == %f\n", str1, str_to_float(str1));
// 	// printf("the string [%s] converted to float is  == %f\n", str2, str_to_float(str2));
// 	// printf("the string [%s] converted to float is  == %f\n", str3, str_to_float(str3));
// 	// printf("the string [%s] converted to float is  == %f\n", str4, str_to_float(str4));
// 	// printf("the string [%s] converted to float is  == %f\n", str5, str_to_float(str5));
// 	// printf("the string [%s] converted to float is  == %f\n", str6, str_to_float(str6));
// 	// printf("the string [%s] converted to float is  == %f\n", str7, str_to_float(str7));
// 	// printf("the string [%s] converted to float is  == %f\n", str8, str_to_float(str8));
// 	// printf("is atoi test %d\n", ft_atoi("0"));
// 	printf("is the string [%s] a color? == %s\n", str1, is_str_rgb(str1) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str2, is_str_rgb(str2) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str3, is_str_rgb(str3) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str4, is_str_rgb(str4) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str5, is_str_rgb(str5) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str6, is_str_rgb(str6) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str7, is_str_rgb(str7) ? "True" : "False");
// 	printf("is the string [%s] a color? == %s\n", str8, is_str_rgb(str8) ? "True" : "False");
// 	// printf("is atoi test %d\n", ft_atoi("0"));
// 	return (0);
// }
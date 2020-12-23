/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:20:36 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 18:48:49 by hlimouni         ###   ########.fr       */
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
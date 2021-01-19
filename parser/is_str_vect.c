/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:19:40 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:54:46 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (!(trimd_str = ft_strtrim(str, ",")))
		return (-1);
	if (ft_strcmp(str, trimd_str) != 0)
	{
		ft_free_null((void **)&trimd_str);
		return (0);
	}
	ft_free_null((void **)&trimd_str);
	if (!(arr = ft_split(str, ',')))
		return (-1);
	i = 0;
	while (is_str_float(arr[i]))
		i++;
	free_2d_array(&arr);
	return (i == 3 ? 1 : 0);
}
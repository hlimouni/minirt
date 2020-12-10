/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:01:50 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/09 20:29:23 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_printf/libft/libft.h"

int     is_str_vect(char *str)
{
	int		i;
	char	**arr;
	char	*trimd_str;
	char	comma_count;
	
	comma_count = ft_strchar_count(str, ',');
	if (comma_count == 2)
	{
		trimd_str = ft_strtrim(str, ",");
		if (ft_strcmp(str, trimd_str) != 0)
		{
			ft_free_null(trimd_str);
			return (0);
		}
		ft_free_null(trimd_str);
		arr = ft_split(str, ',');
		i = 0;
		while (is_str_float(arr[i]))
			i++;
		free_2d_array(&arr);
		if (i == 3)
			return (1);
	}
	return (0);
}
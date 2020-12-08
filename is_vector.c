/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:40:04 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/08 14:53:08 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "minirt.h"
#include <stdio.h>

int		is_str_int(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i++]))
	if (ft_strlen(str) == i)
		return (1);
	return (0);
}

int		is_str_float(char *str)
{
	int		point_ct;
	char	*point_ptr;
	int		i;

	point_ct = ft_strchar_count(str, '.');
	point_ptr = ft_strchr(str, '.');
	if (point_ct == 1 || point_ct == 0)
	{
		if (point_ptr == NULL)
		{
			if (arr[i][j] == '-' || arr[i][j] == '+')
				j++;
			while (ft_isdigit(arr[i][j++]))
			if (ft_strlen(arr[i]) == j)
				dim += i;
			i++;		
		}
	}
}

void	free_2d_array(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
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

int		main(void)
{
	t_vect	vector;
	char	*str = "000233,523,111029";

	printf("%d\n", is_3x3vect(str));
	if (is_3x3vect(str))
	{
		vector = arr_to_vect(str);
		printf("%f, %f, %f\n", vector.x, vector.y, vector.z);
	}
	return (0);
}

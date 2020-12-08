/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:40:04 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/08 09:51:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

t_vect	arr_to_vect(char **arr)
{
	t_vect	vect;

	vect.x = ft_atoi(arr[0]);
	vect.y = ft_atoi(arr[1]);
	vect.z = ft_atoi(arr[2]);
	return (vect);
}

t_vect	is_3x3vect(char *str)
{
    char    **arr;
	int		i;
	int		j;
	int		dim;
	t_vect	vect;

    if (!str)
        return (0);
    arr = ft_split(str, ',');
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
		return (dim);
	}
	else
		return (0);
}

int		main(void)
{
	printf("%d\n", is_3x3vect("233,23,423,4222"));
	return (0);
}

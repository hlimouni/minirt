/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:38:25 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 15:21:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect  str_to_vect(char *str)
{
    t_vect  vect;
    char    **arr;

    arr = ft_split(str, ',');
    vect.x = str_tof(arr[0]);
    vect.y = str_tof(arr[1]);
    vect.z = str_tof(arr[2]);
    free_2d_array(&arr);
    return (vect);
}

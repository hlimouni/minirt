/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:38:25 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 16:11:10 by hlimouni         ###   ########.fr       */
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



int     main(void)
{
    t_vect vect;

    vect = str_to_vect("23.55,.5,+22.");
    printf("vect.x == %f, vect.y == %f, vect.z == %f\n", vect.x, vect.y, vect.z);
}
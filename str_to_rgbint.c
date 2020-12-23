/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_rgbint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:58:26 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 18:48:49 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     str_to_rgbint(char *str)
{
    int		color_int;
    t_vect	color_vect;

	color_vect = str_to_vect(str);
	color_int = vectoi(color_vect);
	return (color_int);
}
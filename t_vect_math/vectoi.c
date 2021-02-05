/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:16:34 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 19:02:43 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

int		is_vect_null(t_vect v)
{
	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (1);
	return (0);
}

int		vectoi(t_vect vect)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	t_vect	color_vect;

	color_vect = vect;
	if (color_vect.x > 255.0)
		color_vect.x = 255.0;
	if (color_vect.y > 255.0)
		color_vect.y = 255.0;
	if (color_vect.z > 255.0)
		color_vect.z = 255.0;
	red = (int)color_vect.x;
	green = (int)color_vect.y;
	blue = (int)color_vect.z;
	color = (red << 16 | green << 8 | blue);
	return (color);
}

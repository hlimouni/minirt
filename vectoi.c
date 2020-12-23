/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:16:34 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 16:16:45 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				vectoi(t_vect vect)
{
	int		red;
	int 	green;
	int 	blue;
	int		color;
	double	x;
	double	y;
	double	z;

	if ((x = vect.x) > 255.0)
		x = 255.0;
	if ((y = vect.y) > 255.0)
		y = 255.0;
	if ((z = vect.z) > 255.0)
		z = 255.0;
	red = (int)x;
	green = (int)y;
	blue = (int)z;
	color = (red << 16 | green << 8 | blue);
	return (color);
}
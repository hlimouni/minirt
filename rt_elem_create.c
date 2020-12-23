/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_elem_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:12:46 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/23 19:49:12 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square    rt_square_create(char   **splitd_line)
{
    t_square    square;

    square.origin = str_to_vect(splitd_line[sq_position]);
    square.normal = str_to_vect(splitd_line[sq_normal]);
	square.normal = vect_unit(square.normal);
    square.side = str_tof(splitd_line[sq_side]);
    square.color = str_to_rgbint(splitd_line[sq_color]);
	return (square);
}

t_sphere	rt_sphere_create(char **splitd_line)
{
	t_sphere	sphere;

	sphere.o = str_to_vect(splitd_line[sp_center]);
	sphere.r = str_tof(splitd_line[sp_diameter]);
	sphere.r /= 2;
	sphere.color = str_to_rgbint(splitd_line[sp_color]);
	return (t_sphere);
}
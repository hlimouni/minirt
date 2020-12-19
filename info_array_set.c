/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_array_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:05:19 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/18 21:02:14 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int     *square_info_set(void)
{
        int     *square_info;

        square_info = (int *)malloc(sizeof(int) * (SQ_PARAMS + 1));
        square_info[sq_ID] = rt_square;
        square_info[sq_position] = vector_type;
        square_info[sq_normal] = vector_type;
        square_info[sq_side] = udecimal_type;
        square_info[sq_color] = rgb_type;
        square_info[SQ_PARAMS] = -1;
	return (square_info);
}

static int	*sphere_info_set(void)
{
	int	*sphere_info;

	sphere_info = (int *)malloc(sizeof(int) * (SP_PARAMS + 1));
        sphere[sp_ID] = rt_sphere;
        sphere[sp_center] = vector_type;
        sphere[sp_radius] = udecimal_type;
        sphere[sp_color] = rgb_type;
	sphere[SP_PARAMS] = -1;
	return (sphere_info);
}

int	**info_array_set(void)
{
	int	**info;

	info = (int **)malloc(sizeof(int *) * (RT_ELEMS_COUNT + 1));
	info[rt_square] = square_info_set();
	info[rt_triangle] = triangle_info_set();
	info[rt_plane] = plane_info_set();


	info[RT_ELEMENT_COUNT] = NULL;
	return (info);
}

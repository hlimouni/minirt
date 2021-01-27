/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bases_for_squares.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:37:27 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/22 12:03:17 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** set_base_for_squares is created to prevent the recalculation of the
** the square base for each pixel since it's an unchanged proprety of
** the square, so we calculate the base only once a camera is defined
** (the square base depends on the camera up vector) for each square
** in the scene.
*/

void			set_base_for_squares(t_cam *cam, t_list *list)
{
	t_square	*sq;

	while (list)
	{
		if (list->element == rt_square)
		{
			sq = list->content;
			sq->u = vect_cross(sq->normal, cam->up);
			sq->v = vect_cross(sq->normal, sq->u);
			sq->u = vect_unit(sq->u);
			sq->v = vect_unit(sq->v);
		}
		list = list->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_square_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:40:14 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 11:40:55 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_square_push(char   **splitd_line, t_scene *scene)
{
    t_square    *square;
	t_list		*new_node;

	if (!(square = malloc(sizeof(t_square))))
		return (0);
    square->origin = str_to_vect(splitd_line[sq_position]);
    square->normal = str_to_vect(splitd_line[sq_normal]);
	square->normal = vect_unit(square.normal);
    square->side = str_tof(splitd_line[sq_side]);
    square->color = str_to_rgbint(splitd_line[sq_color]);
	if (!(new_node = ft_lstnew(square)))
		return (0);
	new_node->element = rt_square;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

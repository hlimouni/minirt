/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_triangle_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:41:08 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 11:41:44 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_triangle_push(char **splitd_line, t_scene *scene)
{
	t_triangle	*triangle;
	t_list		*new_node;
	
	if (!(triangle = malloc(sizeof(t_triangle))))
		return (0);
	triangle->pt_a = str_to_vect(splitd_line[tr_1st_pnt]);
	triangle->pt_b = str_to_vect(splitd_line[tr_2nd_pnt]);
	triangle->pt_c = str_to_vect(splitd_line[tr_3rd_pnt]);
	triangle->color = str_to_rgbint(splitd_line[tr_color]);
	if (!(new_node = ft_lstnew(triangle)))
		return (0);
	new_node->element = rt_triangle;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

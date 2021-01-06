/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:38:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 11:39:44 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_plane_push(char **splitd_line, t_scene *scene)
{
	t_plane		*plane;
	t_list		*new_node;
	
	if (!(plane = malloc(sizeof(t_plane))))
		return (0);
	plane->p = str_to_vect(splitd_line[pl_position]);
	plane->n = vect_unit(str_to_vect(splitd_line[pl_normal]));
	plane->color = str_to_rgbint(splitd_line[pl_color]);
	if (!(new_node = ft_lstnew(plane)))
		return (0);
	new_node->element = rt_plane;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

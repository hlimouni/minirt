/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:37:11 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 11:39:55 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_cylinder_push(char **splitd_line, t_scene *scene)
{
	t_cylinder	*cylinder;
	t_list		*new_node;
	
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (0);
	cylinder->origin = str_to_vect(splitd_line[cy_position]);
	cylinder->axis = vect_unit(str_to_vect(splitd_line[cy_axis]));
	cylinder->radius = str_to_(splitd_line[cy_diameter]);
	cylinder->radius /= 2;
	cylinder->height = str_tof(splitd_line[cy_height]);
	cylinder->color = str_to_rgbint(splitd_line[cy_color]);
	if (!(new_node = ft_lstnew(cylinder)))
		return (0);
	new_node->element = rt_cylinder;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

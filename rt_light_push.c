/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:49:29 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 12:49:56 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		rt_light_push(char **splitd_line, t_scene *scene)
{
	t_light		*light;
	t_list		*new_node;
	
	if (!(light = malloc(sizeof(t_light))))
		return (0);
	light->l = vect_unit(str_to_vect(splitd_line[l_position]));
	light->intensity = str_tof(splitd_line[l_bright]);
	light->color = str_to_rgbint(splitd_line[l_color]);
	if (!(new_node = ft_lstnew(light)))
		return (0);
	new_node->element = rt_light;
	ft_lstadd_front(&(scene->lights), new_node);
	return (1);
}

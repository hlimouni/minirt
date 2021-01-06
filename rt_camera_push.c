/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:50:04 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 12:50:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		rt_camera_push(char **splitd_line, t_scene *scene)
{
	t_cam		*camera;
	t_list		*new_node;
	
	if (!(camera = malloc(sizeof(t_cam))))
		return (0);
	camera->c = str_to_vect(splitd_line[c_position]);
	camera->l = vect_unit(str_to_vect(splitd_line[c_orientation]));
	camera->fov = str_tof(splitd_line[c_fov]);
	camera->fov = (cam->fov * M_PI) / 180.0;
	if (!(new_node = ft_lstnew(camera)))
		return (0);
	new_node->element = rt_camera;
	ft_lstadd_front(&(scene->cams), new_node);
	return (1);
}

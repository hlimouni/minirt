/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:16:47 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 19:21:18 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_res_push(char **splitd_line, t_scene *scene)
{
	t_resolution		*resolution;

	if (scene->res)
		return (-1);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (0);
	ft_strtoi(splitd_line[res_height], &(resolution->height));
	ft_strtoi(splitd_line[res_width], &(resolution->width));
	scene->res = resolution;
	return (1);
}

int		rt_amb_push(char **splitd_line, t_scene *scene)
{
	t_amb		*amb;

	if (scene->amb)
		return (-1);
	if (!(amb = malloc(sizeof(t_amb))))
		return (0);
	amb->intensity = str_tof(splitd_line[amb_ratio]);
	amb->color = str_to_rgbint(splitd_line[amb_color]);
	scene->amb = amb;
	return (1);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem_to_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:51:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 18:57:54 by hlimouni         ###   ########.fr       */
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
	t_vect		intensity;

	if (scene->amb)
		return (-1);
	if (!(amb = malloc(sizeof(t_amb))))
		return (0);
	amb->intensity = str_tof(splitd_line[amb_ratio]);
	amb->color = str_to_rgbint(splitd_line[amb_color]);
	amb->color_vect = str_to_vect(splitd_line[amb_color]);
	amb->coeff = vect_const_prod(1.0/255.0, amb->color_vect);
	amb->coeff = vect_const_prod(amb->intensity, amb->coeff);
	scene->amb = amb;
	return (1);
}

int		rt_light_push(char **splitd_line, t_scene *scene)
{
	t_light		*light;
	t_list		*new_node;
	
	if (!(light = malloc(sizeof(t_light))))
		return (0);
	light->l = str_to_vect(splitd_line[l_position]);
	light->intensity = str_tof(splitd_line[l_bright]);
	light->color_vect = str_to_vect(splitd_line[l_color]);
	light->coeff = vect_const_prod(1.0/255.0, light->color_vect);
	light->coeff = vect_const_prod(light->intensity, light->coeff);
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
	// camera->l = vect_unit(str_to_vect(splitd_line[c_orientation]));
	camera->l = str_to_vect(splitd_line[c_orientation]);
	camera->fov = str_tof(splitd_line[c_fov]);
//	camera->fov = (camera->fov * M_PI) / 180.0;
	if (!(new_node = ft_lstnew(camera)))
		return (0);
	new_node->element = rt_camera;
	ft_lstadd_front(&(scene->cams), new_node);
	return (1);
}

int		add_elem_to_scene(t_scene *scene, char **splitd_line)
{
	t_elem_push	elem_push_arr[rt_elems_num];
	int			elem;

	elem = is_str_ID(splitd_line[0]);
	elem_push_arr[rt_camera] = rt_camera_push;
	elem_push_arr[rt_ambiant] = rt_amb_push;
	elem_push_arr[rt_resolution] = rt_res_push;
	elem_push_arr[rt_light] = rt_light_push;
	elem_push_arr[rt_square] = rt_square_push;
	elem_push_arr[rt_triangle] = rt_triangle_push;
	elem_push_arr[rt_sphere] = rt_sphere_push;
	elem_push_arr[rt_cylinder] = rt_cylinder_push;
	elem_push_arr[rt_plane] = rt_plane_push;
	elem_push_arr[rt_rotation] = NULL;
	elem_push_arr[rt_translation] = NULL;
	return (elem_push_arr[elem](splitd_line, scene));
}

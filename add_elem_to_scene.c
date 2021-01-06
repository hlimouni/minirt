/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem_to_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:51:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 12:53:26 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (elem_push_arr[elem](scene, splitd_line));
}

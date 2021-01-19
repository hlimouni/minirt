/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem_to_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:51:30 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:51:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

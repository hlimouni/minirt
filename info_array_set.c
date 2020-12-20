/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_array_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:05:19 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/20 13:13:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		*square_info_set(void)
{
	int		*square_info;

	square_info = (int *)malloc(sizeof(int) * (sq_params_num + 1));
	square_info[sq_ID] = rt_square;
	square_info[sq_position] = vector_type;
	square_info[sq_normal] = vector_type;
	square_info[sq_side] = udecimal_type;
	square_info[sq_color] = rgb_type;
	square_info[sq_params_num] = -1;
	return (square_info);
}

int		*sphere_info_set(void)
{
	int	*sphere_info;

	sphere_info = (int *)malloc(sizeof(int) * (sp_params_num + 1));
	sphere_info[sp_ID] = rt_sphere;
	sphere_info[sp_center] = vector_type;
	sphere_info[sp_radius] = udecimal_type;
	sphere_info[sp_color] = rgb_type;
	sphere_info[sp_params_num] = -1;
	return (sphere_info);
}

int		*triangle_info_set(void)
{
	int		*triangle_info;

	sphere_info = (int *)malloc(sizeof(int) * (tr_params_num + 1));
	triangle_info[tr_ID] = rt_triangle;
	triangle_info[tr_1st_pnt] = vector_type;
	triangle_info[tr_2nd_pnt] = vector_type;
	triangle_info[tr_3rd_pnt] = vector_type;
	triangle_info[tr_color] = rgb_type;
	triangle_info[tr_params_num] = -1;
	return (triangle_info);
}

int		*cylinder_info_set(void)
{
	int		*cylinder_info;

	cylinder_info = (int *)malloc(sizeof(int) * (cy_params_num + 1));
	cylinder_info[cy_ID] = rt_cylinder;
	cylinder_info[cy_position] = vector_type;
	cylinder_info[cy_axis] = vector_type;
	cylinder_info[cy_diameter] = udecimal_type;
	cylinder_info[cy_height] = udecimal_type;
	cylinder_info[cy_color] = rgb_type;
	cylinder_info[cy_params_num] = -1;
	return (cylinder_info);
}

int		*plane_info_set(void)
{
	int		*plane_info;

	plane_info = (int *)malloc(sizeof(int) * (pl_params_num + 1));
	plane_info[pl_ID] = rt_plane;
	plane_info[pl_position] = vector_type;
	plane_info[pl_normal] = vector_type;
	plane_info[pl_color] = rgb_type;
	plane_info[pl_params_num] = -1;
	return (plane_info);
}

int		*camera_info_set(void)
{
	int		*camera_info;

	camera_info = (int *)malloc(sizeof(int) * (c_params_num + 1));
	camera_info[c_ID] = rt_camera;
	camera_info[c_position] = vector_type;
	camera_info[c_orientation] = vector_type;
	camera_info[c_fov] = angle_type;
	camera_info[c_params_num] = -1;
	return (camera_info);
}

int		*res_info_set(void)
{
	int		*res_info;

	res_info = (int *)malloc(sizeof(int) * (res_params_num + 1));
	res_info[res_ID] = rt_resolution;
	res_info[res_width] = uint_type;
	res_info[res_height] = uint_type;
	res_info[res_params_num] = -1;
	return (res_info);
}
int		*amb_info_set(void)
{
	int		*amb_info;

	amb_info = (int *)malloc(sizeof(int) * (amb_params_num + 1));
	amb_info[amb_ID] = rt_ambiant;
	amb_info[amb_ratio] = ratio_type;
	amb_info[amb_color] = rgb_type;
	amb_info[amb_params_num] = -1;
	return (amb_info);
}

int		*light_info_set(void)
{
	int		*light_info;

	light_info = (int *)malloc(sizeof(int) * (l_params_num + 1));
	light_info[l_ID] = rt_light;
	light_info[l_position] = vector_type;
	light_info[l_bright] = ratio_type;
	light_info[l_color] = rgb_type;
	light_info[l_params_num] = -1;
	return (light_info);
}

int		*rot_info_set(void)
{
	int		*rot_info;

	rot_info = (int *)malloc(sizeof(int) * (rot_params_num + 1));
	rot_info[rot_ID] = rt_rotation;
	rot_info[rot_object] = ID_type;
	rot_info[rot_pitch] = angle_type;
	rot_info[rot_yaw] = angle_type;
	rot_info[rot_roll] = angle_type;
	rot_info[rot_params_num] = -1;
	return (rot_info);
}
int		*tran_info_set(void)
{
	int		*tran_info;

	tran_info = (int *)malloc(sizeof(int) * (tran_params_num + 1));
	tran_info[tran_ID] = rt_translation;
	tran_info[tran_object] = ID_type;
	tran_info[tran_vect] = vector_type;
	tran_info[tran_params_num] = -1;
	return (tran_info);
}

int		*set_elem_info(int element)
{
	t_info_set	set_elem_arr[rt_elems_num];
	
	if (element >= rt_elems_num || element < 0)
		return (NULL);
	set_elem_arr[rt_camera] = camera_info_set;
	set_elem_arr[rt_ambiant] = amb_info_set;
	set_elem_arr[rt_resolution] = res_info_set;
	set_elem_arr[rt_light] = light_info_set;
	set_elem_arr[rt_square] = square_info_set;
	set_elem_arr[rt_triangle] = triangle_info_set;
	set_elem_arr[rt_sphere] = sphere_info_set;
	set_elem_arr[rt_cylinder] = cylinder_info_set;
	set_elem_arr[rt_plane] = plane_info_set;
	set_elem_arr[rt_translation] = tran_info_set;
	set_elem_arr[rt_rotation] = rot_info_set;
	return (set_elem_arr[element]());
	
	// if (element == rt_ambiant)
	// 	return (ambiant_info_set());
	// else if (element == rt_camera)
	// 	return (camera_info_set());
	// else if (element == rt_cylinder)
	// 	return (cylinder_info_set());
	// else if (element == rt_plane)
	// 	return (plane_info_set());
	// else if (element == rt_sphere
	// 	return (sphere_info_set());
	// else if (element == rt_resolution)
	// 	return (res_info_set());
	// else if (element == rt_trinagle)
	// 	return (triangle_info_set());
	// else if (element == rt_square)
	// 	return (square_info_set());
	// else if (element == rt_translation)
	// 	return (tran_info_set());
	// else if (element == rt_rotation)
	// 	return (rot_info_set());
	// else
	// 	return (NULL);
}

int	**array_info_set(void)
{
	int	**info_arr;
	int	element;

	info_arr = (int **)malloc(sizeof(int *) * (rt_elems_num + 1));
	element = 0;
	while (element < rt_elems_num)
	{
		info_arr[element] = set_elem_info(element);
		element++;
	}
	info[rt_elems_num] = NULL;
	return (info_arr);
}

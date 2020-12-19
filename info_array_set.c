/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_array_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:05:19 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/19 21:02:14 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	*square_info_set(void)
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

static int	*sphere_info_set(void)
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

static int	*triangle_info_set(void)
{
	int		*triangle_info;

	sphere_info = (int *)malloc(sizeof(int) * (tr_params_num + 1));
	triangle_info[tr_ID] = rt_triangle;
	triangle_info[tr_1st_pnt] = vector_type;
	triangle_info[tr_2nd_pnt] = vector_type;
	triangle_info[tr_3rd_pnt] = vector_type;
	triangle_info[tr_color] = rgb_type;
	triangle_info[tr_params_num] = -1;
}


static	int *set_elem_info(int element)
{
	t_info_set	set_elem_arr[rt_elems_num];
	
	if (element >= rt_elems_num || element < 0)
		return (NULL);
	set_elem_arr[rt_ambiant] = &ambiant_info_set;
	set_elem_arr[rt_camera] = &camera_info_set;
	set_elem_arr[rt_cylinder] = &cylinder_info_set;
	set_elem_arr[rt_plane] = &plane_info_set;
	set_elem_arr[sphere] = &sphere_info_set;
	set_elem_arr[rt_res] = &res_info_set;
	set_elem_arr[rt_triangle] = &triangle_info_set;
	set_elem_arr[rt_square] = &square_info_set;
	set_elem_arr[rt_tran] = &tran_info_set;
	set_elem_arr[rt_rot] = &rot_info_set;
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
	int	**info;

	info = (int **)malloc(sizeof(int *) * (RT_ELEMS_COUNT + 1));
	info[RT_ELEMS_COUNT] = NULL;
	return (info);
}

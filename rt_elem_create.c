/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_elem_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:12:46 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/28 16:57:42 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square    rt_square_create(char   **splitd_line)
{
    t_square    square;

    square.origin = str_to_vect(splitd_line[sq_position]);
    square.normal = str_to_vect(splitd_line[sq_normal]);
	square.normal = vect_unit(square.normal);
    square.side = str_tof(splitd_line[sq_side]);
    square.color = str_to_rgbint(splitd_line[sq_color]);
	return (square);
}

void	*rt_square_create(char   **splitd_line)
{
    t_square    *square;

	square = (t_square *)malloc(sizeof(square));
    square->origin = str_to_vect(splitd_line[sq_position]);
    square->normal = str_to_vect(splitd_line[sq_normal]);
	square->normal = vect_unit(square.normal);
    square->side = str_tof(splitd_line[sq_side]);
    square->color = str_to_rgbint(splitd_line[sq_color]);
	return (square);
}

t_sphere	rt_sphere_create(char **splitd_line)
{
	t_sphere	sphere;

	sphere.o = str_to_vect(splitd_line[sp_center]);
	sphere.r = str_tof(splitd_line[sp_diameter]);
	sphere.r /= 2;
	sphere.color = str_to_rgbint(splitd_line[sp_color]);
	return (sphere);
}

t_triangle	rt_triangle_create(char **splitd_line)
{
	t_triangle		triangle;

	triangle.pt_a = str_to_vect(splitd_line[tr_1st_pnt]);
	triangle.pt_b = str_to_vect(splitd_line[tr_2nd_pnt]);
	triangle.pt_c = str_to_vect(splitd_line[tr_3rd_pnt]);
	triangle.color = str_to_rgbint(splitd_line[tr_color]);
	return (triangle);
}
t_cylinder	rt_cylinder_create(char **splitd_line)
{
	t_cylinder		cylinder;

	cylinder.origin = str_to_vect(splitd_line[cy_position]);
	cylinder.axis = str_to_vect(splitd_line[cy_axis]);
	cylinder.axis = vect_unit(cylinder.axis);
	cylinder.radius = str_to_(splitd_line[cy_diameter]);
	cylinder.radius /= 2;
	cylinder.height = str_tof(splitd_line[cy_height]);
	cylinder.color = str_to_rgbint(splitd_line[cy_color]);
	return (cylinder);
}
t_plane	rt_plane_create(char **splitd_line)
{
	t_plane		plane;

	plane.p = str_to_vect(splitd_line[pl_position]);
	plane.n = str_to_vect(splitd_line[pl_normal]);
	plane.n /= 2;
	plane.color = str_to_rgbint(splitd_line[pl_color]);
	return (plane);
}
t_cam	rt_cam_create(char **splitd_line)
{
	t_cam		cam;

	cam.c = str_to_vect(splitd_line[c_position]);
	cam.l = str_to_vect(splitd_line[c_orientation]);
	cam.fov = str_tof(splitd_line[c_fov]);
	return (cam);
}
t_resolution	rt_resolution_create(char **splitd_line)
{
	t_resolution		resolution;

	ft_strtoi(splitd_line[res_height], &(resolution.height));
	ft_strtoi(splitd_line[res_width], &(resolution.width));
	return (resolution);
}
t_amb	rt_amb_create(char **splitd_line)
{
	t_amb		amb;

	amb.intensity = str_tof(splitd_line[amb_ratio]);
	amb.color = str_to_rgbint(splitd_line[amb_color]);
	return (amb);
}
t_light	rt_light_create(char **splitd_line)
{
	t_light		light;

	light.l = str_to_vect(splitd_line[l_position]);
	light.intensity = str_tof(splitd_line[l_bright]);
	light.color = str_to_rgbint(splitd_line[l_color]);
	return (light);
}

t_translation	rt_translation_apply(char **splitd_line, t_list	*objs)
{
	t_translation		translation;
	translation.obj_ID = is_str_ID(splitd_line[tran_object]);
	translation.vector = str_to_vect(splitd_line[tran_vect]);
	return (translation);
}

t_rotation		rt_rotation_apply(char **splitd_line, t_list *obj)
{
	t_rotation		rotation;

	rotation.obj_ID = is_str_ID(splitd_line[rot_object]);
	rotation.pitch = str_tof(splitd_line[rot_pitch]);
	rotation.yaw = str_tof(splitd_line[rot_yaw]);
	rotation.roll = str_tof(splitd_line[rot_roll]);
	return (rotation);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_elem_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:12:46 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:20:02 by hlimouni         ###   ########.fr       */
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
t_light	rt_light_create(char **splitd_line)
{
	t_light		light;

	light.l = str_to_vect(splitd_line[l_position]);
	light.intensity = str_tof(splitd_line[l_bright]);
	light.color = str_to_rgbint(splitd_line[l_color]);
	return (light);
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

t_sphere	rt_sphere_create(char **splitd_line)
{
	t_sphere	sphere;

	sphere.o = str_to_vect(splitd_line[sp_center]);
	sphere.r = str_tof(splitd_line[sp_diameter]);
	sphere.r /= 2;
	sphere.color = str_to_rgbint(splitd_line[sp_color]);
	return (sphere);
}
int		rt_sphere_push(char **splitd_line, t_scene *scene)
{
	t_sphere	*sphere;
	t_list		*new_node;
	
	if (!(sphere = malloc(sizeof(t_sphere))))
		return (0);
	sphere->o = str_to_vect(splitd_line[sp_center]);
	sphere->r = str_tof(splitd_line[sp_diameter]);
	sphere->r /= 2;
	sphere->color = str_to_rgbint(splitd_line[sp_color]);
	if (!(new_node = ft_lstnew(sphere)))
		return (0);
	new_node->element = rt_sphere;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

t_triangle	rt_triangle_create(char **splitd_line)
{
	t_triangle		triangle;

	return (triangle);
}

int		rt_triangle_push(char **splitd_line, t_scene *scene)
{
	t_triangle	*triangle;
	t_list		*new_node;
	
	if (!(triangle = malloc(sizeof(t_triangle))))
		return (0);
	triangle->pt_a = str_to_vect(splitd_line[tr_1st_pnt]);
	triangle->pt_b = str_to_vect(splitd_line[tr_2nd_pnt]);
	triangle->pt_c = str_to_vect(splitd_line[tr_3rd_pnt]);
	triangle->color = str_to_rgbint(splitd_line[tr_color]);
	if (!(new_node = ft_lstnew(triangle)))
		return (0);
	new_node->element = rt_triangle;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

t_cylinder	rt_cylinder_create(char **splitd_line)
{
	t_cylinder		cylinder;

	return (cylinder);
}

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

t_plane	rt_plane_create(char **splitd_line)
{
	t_plane		plane;

	return (plane);
}

int		rt_plane_push(char **splitd_line, t_scene *scene)
{
	t_plane		*plane;
	t_list		*new_node;
	
	if (!(plane = malloc(sizeof(t_plane))))
		return (0);
	plane->p = str_to_vect(splitd_line[pl_position]);
	plane->n = vect_unit(str_to_vect(splitd_line[pl_normal]));
	plane->color = str_to_rgbint(splitd_line[pl_color]);
	if (!(new_node = ft_lstnew(plane)))
		return (0);
	new_node->element = rt_plane;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

t_cam	rt_cam_create(char **splitd_line)
{
	t_cam		cam;

	return (cam);
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

int		rt__push(char **splitd_line, t_scene *scene)
{
	t_		*;
	t_list		*new_node;
	
	if (!( = malloc(sizeof(t_))))
		return (0);
	if (!(new_node = ft_lstnew()))
		return (0);
	new_node->element = rt_;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

int		rt_square_push(char   **splitd_line, t_scene *scene)
{
    t_square    *square;
	t_list		*new_node;

	if (!(square = malloc(sizeof(t_square))))
		return (0);
    square->origin = str_to_vect(splitd_line[sq_position]);
    square->normal = str_to_vect(splitd_line[sq_normal]);
	square->normal = vect_unit(square.normal);
    square->side = str_tof(splitd_line[sq_side]);
    square->color = str_to_rgbint(splitd_line[sq_color]);
	if (!(new_node = ft_lstnew(square)))
		return (0);
	new_node->element = rt_square;
	ft_lstadd_front(&(scene->objs), new_node);
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

// void	*rt_square_create(char   **splitd_line)
// {
//     t_square    *square;

// 	square = (t_square *)malloc(sizeof(square));
//     square->origin = str_to_vect(splitd_line[sq_position]);
//     square->normal = str_to_vect(splitd_line[sq_normal]);
// 	square->normal = vect_unit(square.normal);
//     square->side = str_tof(splitd_line[sq_side]);
//     square->color = str_to_rgbint(splitd_line[sq_color]);
// 	return (square);
// }

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


t_translation	rt_translation_apply(char **splitd_line, t_list	*objs)
{
	t_translation		translation;
	translation.obj_ID = str_to_elem(splitd_line[tran_object]);
	translation.vector = str_to_vect(splitd_line[tran_vect]);
	return (translation);
}

t_rotation		rt_rotation_apply(char **splitd_line, t_list *obj)
{
	t_rotation		rotation;

	rotation.obj_ID = str_to_elem(splitd_line[rot_object]);
	rotation.yaw = str_tof(splitd_line[rot_yaw]);
	rotation.pitch = str_tof(splitd_line[rot_pitch]);
	rotation.roll = str_tof(splitd_line[rot_roll]);
	return (rotation);
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

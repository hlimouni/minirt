/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:11:56 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/08 07:29:10 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int		rt_cylinder_push(char **splitd_line, t_scene *scene)
{
	t_cylinder	*cylinder;
	t_list		*new_node;
	
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (0);
	cylinder->origin = str_to_vect(splitd_line[cy_position]);
	cylinder->axis = vect_unit(str_to_vect(splitd_line[cy_axis]));
	cylinder->radius = str_tof(splitd_line[cy_diameter]);
	cylinder->radius /= 2;
	cylinder->height = str_tof(splitd_line[cy_height]);
	cylinder->color = str_to_rgbint(splitd_line[cy_color]);
	if (!(new_node = ft_lstnew(cylinder)))
		return (0);
	new_node->element = rt_cylinder;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
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

int		rt_square_push(char   **splitd_line, t_scene *scene)
{
    t_square    *square;
	t_list		*new_node;

	if (!(square = malloc(sizeof(t_square))))
		return (0);
    square->origin = str_to_vect(splitd_line[sq_position]);
    square->normal = str_to_vect(splitd_line[sq_normal]);
	square->normal = vect_unit(square->normal);
    square->side = str_tof(splitd_line[sq_side]);
    square->color = str_to_rgbint(splitd_line[sq_color]);
	if (!(new_node = ft_lstnew(square)))
		return (0);
	new_node->element = rt_square;
	ft_lstadd_front(&(scene->objs), new_node);
	return (1);
}

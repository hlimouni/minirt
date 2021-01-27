/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:23:36 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:18:50 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	transform_err_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Wrong use of transformation in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd("\n", 2);
}

t_list	*find_elem_tra(int elem_tofind, t_scene *scene)
{
	t_list *lst;

	lst = NULL;
	if (elem_tofind == rt_light)
		return (scene->lights);
	if (elem_tofind == rt_camera)
		return (scene->cams);
	if (elem_tofind == rt_sphere || elem_tofind == rt_cylinder ||
			elem_tofind == rt_plane || elem_tofind == rt_square ||
				elem_tofind == rt_triangle)
	{
		lst = scene->objs;
		while (lst)
		{
			if (lst->element == elem_tofind)
				break ;
			lst = lst->next;
		}
	}
	return (lst);
}

t_list	*find_elem_rot(int elem_tofind, t_scene *scene)
{
	t_list *lst;

	lst = NULL;
	if (elem_tofind == rt_camera)
		return (scene->cams);
	if (elem_tofind == rt_cylinder ||
			elem_tofind == rt_plane || elem_tofind == rt_square)
	{
		lst = scene->objs;
		while (lst)
		{
			if (lst->element == elem_tofind)
				break ;
			lst = lst->next;
		}
	}
	return (lst);
}

void	elem_translate(t_vect *tra, t_list *node)
{
	void	*cont;

	cont = node->content;
	if (node->element == rt_light)
		((t_light *)cont)->l = vect_sum(((t_light *)cont)->l, *tra);
	else if (node->element == rt_camera)
		((t_cam *)cont)->c = vect_sum(((t_cam *)cont)->c, *tra);
	else if (node->element == rt_sphere)
		((t_sphere *)cont)->o = vect_sum(((t_sphere *)cont)->o, *tra);
	else if (node->element == rt_cylinder)
		((t_cylinder *)cont)->origin = vect_sum(((t_cylinder *)cont)->origin,
												*tra);
	else if (node->element == rt_plane)
		((t_plane *)cont)->p = vect_sum(((t_plane *)cont)->p, *tra);
	else if (node->element == rt_square)
		((t_square *)cont)->origin = vect_sum(((t_square *)cont)->origin, *tra);
	else if (node->element == rt_triangle)
	{
		((t_triangle *)cont)->pt_a = vect_sum(((t_triangle *)cont)->pt_a, *tra);
		((t_triangle *)cont)->pt_a = vect_sum(((t_triangle *)cont)->pt_a, *tra);
		((t_triangle *)cont)->pt_a = vect_sum(((t_triangle *)cont)->pt_a, *tra);
	}
}

t_vect	vect_rot(t_vect vec, double phi, double theta, double psi)
{
	t_mat3x3	mat;
	t_vect		rot_vect;

	mat.line1 = (t_vect)
	{
		.x = cos(psi) * cos(theta),
		.y = cos(psi) * sin(theta) * sin(phi) - sin(psi) * cos(phi),
		.z = cos(psi) * sin(theta) * cos(phi) + sin(psi) * sin(phi)
	};
	mat.line2 = (t_vect)
	{
		.x = sin(psi) * cos(theta),
		.y = sin(psi) * sin(theta) * sin(phi) + cos(psi) * cos(phi),
		.z = sin(psi) * sin(theta) * cos(phi) - cos(psi) * sin(phi)
	};
	mat.line3 = (t_vect)
	{
		.x = -sin(theta),
		.y = cos(theta) * sin(phi),
		.z = cos(theta) * cos(phi)
	};
	rot_vect = mat_vect_prod(mat, vec);
	return (rot_vect);
}

void	elem_rotate(double phi, double theta,double psi, t_list *node)
{
	void	*cont;

	cont = node->content;
	if (node->element == rt_camera)
		((t_cam *)cont)->l = vect_rot(((t_cam *)cont)->l, phi, theta, psi);
	else if (node->element == rt_cylinder)
		((t_cylinder *)cont)->axis = vect_rot(((t_cylinder *)cont)->axis,
												phi, theta, psi);
	else if (node->element == rt_plane)
		((t_plane *)cont)->n = vect_rot(((t_plane *)cont)->n, phi, theta, psi);
	else if (node->element == rt_square)
		((t_square *)cont)->normal = vect_rot(((t_square *)cont)->normal,
											phi, theta, psi);
}

int		rt_tran_apply(char **splitd_line, t_scene *scene)
{
	int				elem;
	t_vect			tra;
	t_list			*list;

	elem = str_to_elem(splitd_line[tran_object]);
	tra = str_to_vect(splitd_line[tran_vect]);
	if (!(list = find_elem_tra(elem, scene)))
		return (rt_translation);
	elem_translate(&(tra), list);
	return (1);
}

int		rt_rot_apply(char **splitd_line, t_scene *scene)
{
	int				elem;
	t_list			*list;
	double			phi;
	double			theta;
	double			psi;
	
	elem = str_to_elem(splitd_line[rot_object]);
	phi = str_tof(splitd_line[rot_phi]) * M_PI / 180.0;
	theta = str_tof(splitd_line[rot_theta]) * M_PI / 180.0;
	psi = str_tof(splitd_line[rot_psi]) * M_PI / 180.0;
	if (!(list = find_elem_rot(elem, scene)))
		return (rt_rotation);
	elem_rotate(phi, theta, psi, list);
	return (1);
}


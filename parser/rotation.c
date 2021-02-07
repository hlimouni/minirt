/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:52:46 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:18:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	elem_rotate(double phi, double theta, double psi, t_list *node)
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

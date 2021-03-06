/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:50:35 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/29 10:16:57 by hlimouni         ###   ########.fr       */
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
		((t_triangle *)cont)->pt_b = vect_sum(((t_triangle *)cont)->pt_b, *tra);
		((t_triangle *)cont)->pt_c = vect_sum(((t_triangle *)cont)->pt_c, *tra);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:23:36 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/25 19:07:18 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


void	transform_err_msg(int line)
{
	ft_putstr_fd("Error\nminiRT: Transformation in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" cannot be performed\n", 2);
}

t_list	*find_element(int elem, t_scene *scene)
{
	t_list *lst;

	lst = NULL;
	if (elem == rt_light)
		return (scene->lights);
	else if (elem == rt_camera)
		return (scene->cams);
	else if (elem = rt_sphere || elem == rt_cylinder || elem == rt_plane
			|| elem == rt_square || elem == rt_triangle)
	{
		lst = scene->objs;
		while (lst)
		{
			if (lst->element == element)
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}

int	set_elem_origin(t_vect *tra, t_list *node)
{
	void	*cont;
	int		elem;

	content = NULL;
	elem = 0;
	if (!node)
		return (0);
	cont = node->content;
	elem = node->element;
	if (elem == rt_light)
		((t_light *)cont)->l = vect_sum((t_light *)cont)->l, *tra);
	else if (elem == rt_camera)
		((t_cam *)cont)->c = vect_sum(((t_cam *)cont)->c, *tra);
	else if (elem == rt_sphere)
		((t_sphere *)cont)->o = vect_sum((t_sphere *)cont)->o, *tra);
	else if (elem == rt_cylinder)
		((t_cylinder *)cont)->origin = vect_sum(((t_cylinder *)cont)->origin, *tra);
	else if (elem == rt_plane)
		((t_plane *)cont)->p = vect_sum(((t_plane *)cont)->p, *tra);
	else if (elem == rt_square)
		((t_square *)cont)->origin = vect_sum(((t_square *)cont)->origin, *tra);

}

int		rt_tran_apply(char **splitd_line, t_scene *scene)
{
	t_translation	tran;
	t_vect			origin;

	tran.obj_ID = is_str_ID(splitd_line[tran_object]);
	tran.vector = str_to_vect(splitd_line[tran_vect]);
	
}
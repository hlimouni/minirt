/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:39:08 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 11:39:29 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

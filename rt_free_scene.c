/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:10:43 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 18:10:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_free_scene(t_scene *scene)
{
	ft_free_null(&(void *)(scene->amb));
	ft_free_null(&(void *)(scene->res));
	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->objs), free);
}

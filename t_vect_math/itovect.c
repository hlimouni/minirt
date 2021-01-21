/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itovect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:15:31 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 15:13:24 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

t_vect			itovect(int color)
{
	t_vect			vect;
	unsigned char	*rgb;

	rgb = (unsigned char *)(&color);
	vect.x = (double)rgb[2];
	vect.y = (double)rgb[1];
	vect.z = (double)rgb[0];
	return (vect);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_rt_quadtratic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:41:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 15:13:41 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

double			solve_rt_quadratic(double a, double b, double c)
{
	double		t1;
	double		t2;
	double		delta;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t1 < 0 && t2 < 0)
		return (-1);
	if ((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0))
		return (t1 > t2 ? t1 : t2);
	return (t1 < t2 ? t1 : t2);
}

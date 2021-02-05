/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:53:53 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 18:59:32 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

double		vect_norm(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vect		vect_unit(t_vect v)
{
	t_vect	unit;
	double	norm;

	norm = vect_norm(v);
	if (norm != 0.0)
	{
		unit.x = v.x / norm;
		unit.y = v.y / norm;
		unit.z = v.z / norm;
		return (unit);
	}
	return (v);
}

t_vect		vect_const_prod(double cst, t_vect v)
{
	t_vect	vect;

	vect.x = cst * v.x;
	vect.y = cst * v.y;
	vect.z = cst * v.z;
	return (vect);
}

t_vect		vect_const_sum(double cst, t_vect v)
{
	v.x = cst + v.x;
	v.y = cst + v.y;
	v.z = cst + v.z;
	return (v);
}

int			is_vect_equal(t_vect u, t_vect v)
{
	if (u.x == v.x && u.y == v.y && u.z == v.z)
		return (1);
	return (0);
}

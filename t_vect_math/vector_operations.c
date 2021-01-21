/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:51:07 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 15:13:58 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

t_vect  vect_diff(t_vect u, t_vect v)
{
    t_vect  diff;

    diff.x = u.x - v.x;
    diff.y = u.y - v.y;
    diff.z = u.z - v.z;
    return (diff);
}

t_vect  vect_sum(t_vect u, t_vect v)
{
    t_vect  sum;

    sum.x = u.x + v.x;
    sum.y = u.y + v.y;
    sum.z = u.z + v.z;
    return (sum);
}

t_vect  vect_prod(t_vect u, t_vect v)
{
    t_vect  prd;

    prd.x = u.x * v.x;
    prd.y = u.y * v.y;
    prd.z = u.z * v.z;
    return (prd);
}

t_vect  vect_cross(t_vect u, t_vect v)
{
    t_vect  cross;

    cross.x = u.y * v.z - u.z * v.y;
    cross.y = u.z * v.x - u.x * v.z;
    cross.z = u.x * v.y - u.y * v.x;
    return (cross);
}

double   vect_dot(t_vect u, t_vect v)
{
    return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double   vect_norm(t_vect v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vect   vect_unit(t_vect v)
{
    t_vect  unit;
    double   norm;
    
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

t_vect	vect_const_prod(double cst, t_vect v)
{
    t_vect  vect;

	vect.x = cst * v.x;
	vect.y = cst * v.y;
	vect.z = cst * v.z;
	return (vect);
}

t_vect	vect_const_sum(double cst, t_vect v)
{
	v.x = cst + v.x;
	v.y = cst + v.y;
	v.z = cst + v.z;
	return (v);
}

int     is_vect_equal(t_vect u, t_vect v)
{
    if (u.x == v.x && u.y == v.y && u.z == v.z)
        return (1);
    return (0);
}
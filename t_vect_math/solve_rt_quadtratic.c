/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_rt_quadtratic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:41:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/29 10:09:46 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

t_solution		solve_rt_quadratic(t_coeff *coeff)
{
	t_solution	sol;
	double		delta;

	sol = (t_solution){.t1 = INFINITY, .t2 = INFINITY};
	delta = coeff->b * coeff->b - 4 * coeff->a * coeff->c;
	if (delta < 0)
		return (sol);
	sol.t1 = (-coeff->b - sqrt(delta)) / (2 * coeff->a);
	sol.t2 = (-coeff->b + sqrt(delta)) / (2 * coeff->a);
	return (sol);
}

double		limit_cylinder(t_coeff *coeff, t_ray *ray,
							t_cylinder *cy)
{
	t_vect		hit1;
	t_vect		hit2;
	t_vect		cy_top;
	t_solution	sol;
	t_solution	ret;

	ret.t1 = INFINITY;
	ret.t2 = INFINITY;
	sol = solve_rt_quadratic(coeff);
	if (isinf(sol.t1) && isinf(sol.t2))
		return (-1);
	cy_top = vect_sum(cy->origin, vect_const_prod(cy->height, cy->axis));
	hit1 = vect_sum(ray->origin, vect_const_prod(sol.t1, ray->dir));
	hit2 = vect_sum(ray->origin, vect_const_prod(sol.t2, ray->dir));
	if (sol.t1 > 0 && vect_dot(cy->axis, vect_diff(hit1, cy->origin)) > 0
		&& vect_dot(cy->axis, vect_diff(hit1, cy_top)) < 0)
		ret.t1 = sol.t1;
	if (sol.t2 > 0 && vect_dot(cy->axis, vect_diff(hit2, cy->origin)) > 0
		&& vect_dot(cy->axis, vect_diff(hit2, cy_top)) < 0)
		ret.t2 = sol.t2;
	if (isinf(ret.t1) && isinf(ret.t2))
		return (-1);
	return (ret.t1 < ret.t2 ? ret.t1 : ret.t2);
}
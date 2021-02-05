/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vect_prod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:28:07 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/05 18:29:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vect_math.h"

t_vect	mat_vect_prod(t_mat3x3 mat, t_vect v)
{
	t_vect	prod;

	prod.x = vect_dot(mat.line1, v);
	prod.y = vect_dot(mat.line2, v);
	prod.z = vect_dot(mat.line3, v);
	return (prod);
}

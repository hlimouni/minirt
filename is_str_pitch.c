/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_pitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:50:28 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/02 19:52:00 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_str_pitch(char *str)
{
	return (is_str_float(str) && str_tof(str) >= -90. && str_tof(str) <= 90.);
}
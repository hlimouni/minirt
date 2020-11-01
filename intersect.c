/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:10:32 by hlimouni          #+#    #+#             */
/*   Updated: 2020/10/28 17:26:05 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
# define TMAX 72000

/*
** The intersection of the ray and sphere is computed by solving the quadratic
** equation at*t+bt+c claculted,
** The closest intersection point is returned or -1 if there's no intersection.
** The signbit condition is true when t1 and t2 have different signs (ie, the
** signbit of t1 "XOR" signbit of t2 is not zero).
*/

float  sp_intersect(t_vect ray, t_cam *cam, t_sphere sp)
{
    float   delta;
    float   t1;
    float   t2;
    float   b;
    float   c;
    t_vect  dir;
    t_vect  ray_sp_O;

    dir = vect_unit(vect_diff(ray, cam->c));
    ray_sp_O = vect_diff(cam->c, sp.o);
    b = 2 * vect_dot(dir, ray_sp_O);
    c = vect_dot(ray_sp_O, ray_sp_O) - (sp.d / 2) * (sp.d / 2);
    delta = b * b - 4 * c;
    if (delta < 0)
        return (-1);
    t1 = (- b - sqrt(delta)) / 2;
    t2 = (- b + sqrt(delta)) / 2;
    if (signbit(t1) ^ signbit(t2))
        return (t1 > t2 ? t1 : t2);
    else if (t1 < 0 && t2 < 0)
        return (-1);
	else
        return (t1 < t2 ? t1 : t2);
}

float   pl_intersect(t_vect ray, t_cam *cam, t_plane plane)
{
    t_vect      dir;
    float      dir_dot_n;
    t_vect      p_c;
    float       t;

    dir = vect_diff(ray, cam->c);
    dir_dot_n = vect_dot(dir, plane.n);
    if (dir_dot_n < 0.001)
        return(-1.0);
    else
    {
        p_c = vect_diff(plane.p, cam->c);
        t = vect_dot(p_c, plane.n) / dir_dot_n;
    }
    if (t < 0 || fabs(t) > TMAX)
        return (-1);
    return (fabs(t));
}
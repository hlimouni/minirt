/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:10:32 by hlimouni          #+#    #+#             */
/*   Updated: 2020/11/14 20:43:09 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
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
    // printf("the ray_screen x coordinate is %f\n", ray.x);
    // printf("the ray_screen y coordinate is %f\n", ray.y);
    // printf("the ray_screen z coordinate is %f\n", ray.z);
    //dir = vect_unit(vect_diff(ray, cam->c));
    dir = vect_diff(ray, cam->c);
    // printf("the dir x coordinate is %f\n", dir.x);
    // printf("the dir y coordinate is %f\n", dir.y);
    // printf("the dir z coordinate is %f\n", dir.z);
    dir_dot_n = vect_dot(dir, vect_unit(plane.n));
    // printf("the dir_dot_n is %f\n", dir_dot_n);
    if (fabs(dir_dot_n) > 0.000001)
    {
        p_c = vect_diff(plane.p, cam->c);
        t = vect_dot(p_c, vect_unit(plane.n)) / dir_dot_n;
        return (t >= 0);
        // printf("the solution t is %f\n", t);
    }
    return (-1.0);
    // if (t < 0)
    // // if (t < 0 || fabs(t) > TMAX)
    //     return (-1.0);
    // return (t);
}

float   sq_intersect(t_vect ray_screen, t_cam *cam, t_square square)
{
    t_vect      forward;
    t_vect      ray_object;
    t_vect      u, l;
    t_vect      v;
    t_plane     plane;
    float       t;
    t_vect      origin_to_hit;
    float       u_distance;
    float       v_distance;

    plane.n = square.normal;
    plane.p = square.origin;
    if ((t = pl_intersect(ray_screen, cam, plane) >= 0.0))
    {
        
	    //ray_object = vect_unit(vect_diff(ray_screen, cam->c));
	    ray_object = vect_diff(ray_screen, cam->c);
        printf("the dir is %f %f %f\n", ray_object.x, ray_object.y, ray_object.z);
	    ray_object = vect_const_prod(t, ray_object);
	    ray_object = vect_sum(cam->c, ray_object);
        printf("ray_object %f %f %f\n", ray_object.x, ray_object.y, ray_object.z);
    
        l = vect_unit(cam->l);
        // printf("the l vect is [%f][%f][%f]\n", l.x, l.y, l.z);
        // printf("the sq normal vect is [%f][%f][%f]\n",
                // (square.normal).x, (square.normal).y, (square.normal).z);
        u = vect_cross(l, square.normal);
        // printf("the u vect is [%f][%f][%f]\n", u.x, u.y, u.z);
        if (is_vect_equal(u, itovect(0)))
        {
            u = vect_cross(l, itovect(0x000100));
            // printf("u before normalization [%f][%f][%f]\n", u.x, u.y, u.z);
        }
        u = vect_unit(u);
        v = vect_unit(vect_cross(square.normal, u));
        //printf("v %f %f %f\n",v.x, v.y, v.z);
        //printf("u %f %f %f\n", u.x, u.y, u.z);
        //rintf("the v vect is [%f][%f][%f]\n", v.x, v.y, v.z);
        
// //        u_distance = vect_sum(square.origin, vectu)
    
         origin_to_hit = vect_diff(ray_object, square.origin);
         printf("origin_to_hit %f %f %f\n", origin_to_hit.x, origin_to_hit.y, origin_to_hit.z);
        //   if (fabs(origin_to_hit.x) <= 0.2 && fabs(origin_to_hit.y) <= 0.2 && fabs(origin_to_hit.z) <= 0.2)
        //     {
        //         printf("t is %f\n", t);
        //       return (t);
        //     }
    
        u_distance = vect_dot(origin_to_hit, u);
        v_distance = vect_dot(origin_to_hit, v);
   
        // // printf("u == %f\nv == %f\n", u_distance, v_distance);
        // /*if (1000*(pow(u_distance,2) + pow(v_distance,2)) == vect_dot(origin_to_hit, origin_to_hit))
        // {
        //     printf("hello\n");
        //    // exit(0);
        // }*/
        
        
        // //  printf(" D ^ 2 == %f \n",pow(vect_norm(origin_to_hit),2));
        // // printf("a ^ 2 + b ^ 2 == %f \n",pow(u_distance ,2) + pow(v_distance * vect_norm(v),2));
        // //printf("%f \n",pow(v_distance,2));
        // //if ((u_distance < 0.3 && u_distance > -0.3) && (v_distance < 0.3 && v_distance > -0.3))
        if (fabs(u_distance) < 0.2 && fabs(v_distance) < 0.2)
        // //if (pow(u_distance,2) + pow(v_distance,2) == vect_dot(origin_to_hit, origin_to_hit))
             return (t);
    }
    return(-1.0);
}
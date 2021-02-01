/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:10:32 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/01 17:47:10 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
# define TMAX 3

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
    c = vect_dot(ray_sp_O, ray_sp_O) - sp.r * sp.r;
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
/*

double	sp_intersect2(t_ray *ray, t_sphere *sphere)
{
	double	b;
    double	c;
    t_vect  ray_sp_o;

	ray_sp_o = vect_diff(ray->origin, sphere->o);
	b = 2 * vect_dot(ray->dir, ray_sp_o);
	c = vect_dot(ray_sp_o, ray_sp_o) - sphere->r * sphere->r;
	return (solve_rt_quadratic(1, b, c));
}
*/

float   pl_intersect(t_vect ray, t_cam *cam, t_plane plane)
{
    t_vect      dir;
    float      dir_dot_n;
    t_vect      p_c;
    float       t;
    //  printf("the ray_screen x coordinate is %f\n", ray.x);
    //  printf("the ray_screen y coordinate is %f\n", ray.y);
    //  printf("the ray_screen z coordinate is %f\n", ray.z);
    //dir = vect_diff(ray, cam->c);
    dir = vect_unit(vect_diff(ray, cam->c));
    // printf("the dir x coordinate is %f\n", ray.x);
    // printf("the dir y coordinate is %f\n", ray.y);
    // printf("the dir z coordinate is %f\n", ray.z);
    dir_dot_n = vect_dot(dir, vect_unit(plane.n));
    // if (dir_dot_n != -1.0)
    //     printf("the dir_dot_n is %f\n", dir_dot_n);
    if (fabs(dir_dot_n) > 0.000001)
    {
        p_c = vect_diff(plane.p, cam->c);
        t = vect_dot(p_c, vect_unit(plane.n)) / dir_dot_n;
        // if (t != 3.0)
        //     printf("t %f\n", t);
        if (t >= 0.0)
            return (t);
        // printf("the solution t is %f\n", t);
    }
    return (-1.0);
    // if (t < 0)
    // // if (t < 0 || fabs(t) > TMAX)
    //     return (-1.0);
    // return (t);
}

/*
double	pl_intersect2(t_ray *ray, t_plane *plane)
{
	t_vect	dir_dot_n;
	t_vect	p_o;

	dir_dot_n = vect_dot(ray->dir, plane->n);
	if (fabs(dir_dot_n) > 10e-7)
	{
		p_o = vect_diff(plane->p, ray->origin);
		t = vect_dot(p_o, plane->n) / dir_dot_n;
		if (t >= 0)
			return (t);
	}
	return (-1);
}

void	sq_base_set(t_cam *cam, t_square *sq)
{
    sq->u = vect_cross(vect_unit(sq->normal), cam->up);
    sq->v = vect_cross(vect_unit(sq->normal), sq->u);
	sq->u = vect_unit(sq->u);
	sq->v = vect_unit(sq->v);
}

double	sq_intersect2(t_ray *ray, t_square *sq)
{
	t_plane	plane;
	t_vect	hit;
	t_vect	origin_to_hit;
	double	u_distance;
	double	v_distance;

    plane.n = sq->normal;
    plane.p = sq->origin;
	if ((t = pl_intersect(ray, &plane)) >= 0.0)
    {
		hit = vect_const_prod(t, ray->dir);
	    hit = vect_sum(ray->origin, hit);
		origin_to_hit = vect_diff(hit, sq->origin);
		u_distance = vect_dot(origin_to_hit, sq->u);
        v_distance = vect_dot(origin_to_hit, sq->v);
		if (fabs(u_distance) < sq->side / 2 &&
			fabs(v_distance) < sq->side / 2)
			return (t);
	}
	return (-1);
}
*/

float   sq_intersect(t_vect ray_screen, t_cam *cam, t_square square)
{
    t_vect      forward;
    t_vect      ray_object;
    t_vect      u, l, cam_up;
    t_vect      v;
    t_plane     plane;
    float       t;
    t_vect      origin_to_hit;
    float       u_distance;
    float       v_distance;

    plane.n = square.normal;
    plane.p = square.origin;
   // t = pl_intersect(ray_screen, cam, plane);
  //  printf("t 1 square is %f\n", t);
    if ((t = pl_intersect(ray_screen, cam, plane)) >= 0.0)
    {
 //       if (t != 1.0)
  //          printf("t square %f\n", t);
        
        
	    ray_object = vect_unit(vect_diff(ray_screen, cam->c));
	    //ray_object = vect_diff(ray_screen, cam->c);
        
 //       printf("the dir is %f %f %f\n", ray_object.x, ray_object.y, ray_object.z);
	    ray_object = vect_const_prod(t, ray_object);
	    ray_object = vect_sum(cam->c, ray_object);
  //      printf("ray_object %f %f %f\n", ray_object.x, ray_object.y, ray_object.z);
    /*
    ** The cam_up vector is the up vector of the camera coordinate system it is calculated
    ** just as in the cam_ray_build function.
    ** the u vector defines the intersection between the (forward, right) plane of the camera 
    ** and the square's plane, hence the use of the cross (square_normal x cam_up) which resuls in a
    ** vector perpendicular to each plane's normal <=> the vector belongs to both planes <=> intersection.
    ** Now that we have u as a vector in the plane we construct the base as
    ** (square.origin, square.normal, u, v)
    */
    
        // l = vect_unit(vect_const_prod(-1.0, cam->l));
        // cam_up = vect_cross(itovect(0x000100), l);
        // cam_up = vect_cross(l,cam_up);
        cam_up = cam->up;
        u = vect_cross(vect_unit(square.normal), cam_up);
        v = vect_cross(vect_unit(square.normal), u);
        u = vect_unit(u);
        v = vect_unit(v);
    
        // printf("the l vect is [%f][%f][%f]\n", l.x, l.y, l.z);
        // printf("the sq normal vect is [%f][%f][%f]\n",
 /*               // (square.normal).x, (square.normal).y, (square.normal).z);
        u = vect_cross(l, vect_unit(square.normal));
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
   */ 
         origin_to_hit = vect_diff(ray_object, square.origin);
        //  printf("origin_to_hit %f %f %f\n", origin_to_hit.x, origin_to_hit.y, origin_to_hit.z);
    //       if (fabs(origin_to_hit.x) <= 0.5 && fabs(origin_to_hit.y) <= 0.5 && fabs(origin_to_hit.z) <= 0.5)
    //         {
    //  //           printf("t is %f\n", t);
    //             return (t);
    //         }
    
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
         if (fabs(u_distance) < 0.3 && fabs(v_distance) < 0.3)
         // //if (pow(u_distance,2) + pow(v_distance,2) == vect_dot(origin_to_hit, origin_to_hit))
              return (t);
    }
    return(-1.0);
}

/*
** Quadratic function in rt:
** If delta is negative means no solution so we return a negative value
** than if delta is 0 we return either one of the two solution since they're
** equal.
** If the two solutions have different signs we return the greater one
** but if they are both positive we return the smallest
** of course if they're both negative we return a negative value.
*/


double	solve_rt_quadratic(double a, double b, double c)
{
	double t1;
	double t2;
	double delta;

	delta = b * b - 4 * a * c;
    if (delta < 0)
        return (-1.0);
    t1 = (- b - sqrt(delta)) / (2 * a);
    t2 = (- b + sqrt(delta)) / (2 * a);
    if ((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0))
        return (t1 > t2 ? t1 : t2);
    if (t1 < 0 && t2 < 0)
        return (-1);
    return (t1 < t2 ? t1 : t2);
}


float  cy_intersect(t_vect ray_screen, t_cam *cam, t_cylinder cy)
{
    float   delta;
    float   t1;
    float   t2;
    float   tmin;
    float   tmax;
    float   a;
    float   b;
    float   c;
    t_vect  d;
    t_vect  u;
    t_vect  tmp;
    t_vect  oc_c;
    
    u = vect_unit(cy.axis);
    d = vect_unit(vect_diff(ray_screen, cam->c));
    oc_c = vect_diff(cy.origin, cam->c);
    a = 1 - pow(vect_dot(d, u), 2);
    b = 2 * (vect_dot(d, u) * vect_dot(oc_c, u) - vect_dot(oc_c, d));
    tmp = vect_diff(oc_c, vect_const_prod(vect_dot(oc_c, u), u));
    c = vect_dot(tmp, tmp) - cy.radius * cy.radius;
    delta = b * b - 4 * a * c;
    if (delta < 0)
        return (-1);
    t1 = (- b - sqrt(delta)) / (2 * a);
    t2 = (- b + sqrt(delta)) / (2 * a);
    tmin = vect_dot(u, oc_c) / vect_dot(d, u);
    tmax = (cy.height + vect_dot(u, oc_c)) / vect_dot(d, u);
    // printf("d ")
    // printf("d.u == %f", vect_dot(d, u));
    if (t1 < tmin || t1 > tmax)
        t1 = -1;
    if (t2 < tmin || t2 > tmax)
        t2 = -1;
    if (signbit(t1) ^ signbit(t2))
        return (t1 > t2 ? t1 : t2);
    else if (t1 < 0 && t2 < 0)
        return (-1);
	else
        return (t1 < t2 ? t1 : t2);
}

double		cy_intersect2(t_ray *ray, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;
	t_vect	oc_c;
	
	u = vect_unit(cy.axis);
	d = vect_unit(vect_diff(ray_screen, cam->c));
	oc_c = vect_diff(cy->origin, ray->origin);
	a = 1 - pow(vect_dot(ray->dir, cy->axis), 2);
	b = 2 * (vect_dot(ray->dir, cy->axis) * vect_dot(oc_c, cy->axis);
	b = b - vect_dot(oc_c, ray->dir));
	c = vect_diff(oc_c, vect_const_prod(vect_dot(oc_c, cy->axis), cy->axis));
	c = vect_dot(c, c) - cy->radius * cy->radius;
	t = solve_rt_quadratic(a, b, c);
	if (t < (vect_dot(u, oc_c) / vect_dot(ray->dir, cy->axis)) ||
		t > ((cy->height + vect_dot(cy->axis, oc_c)) / vect_dot(ray->dir, cy->axis)))
		return (-1);
	return (t);
}



 float   tr_intersect(t_vect ray_screen, t_cam *cam, t_triangle *tr)
 {
     t_vect      ray_object;
     t_plane     plane;
     float       t;
     t_vect      origin_to_hit;
     plane.n = vect_cross(vect_diff(tr->pt_b, tr->pt_a), vect_diff(tr->pt_c, tr->pt_a));
     plane.n = vect_unit(plane.n);
     tr->normal = plane.n;
     plane.p = tr->pt_a;
     //t = pl_intersect(ray_screen, cam, plane);
     if ((t = pl_intersect(ray_screen, cam, plane)) >= 0.0)
     {    
 	    ray_object = vect_unit(vect_diff(ray_screen, cam->c));
 	    ray_object = vect_const_prod(t, ray_object);
 	    ray_object = vect_sum(cam->c, ray_object);
         if (vect_dot(plane.n, vect_cross(vect_diff(tr->pt_b, tr->pt_a),
		 			vect_diff(ray_object, tr->pt_a))) >= 0.0 &&
         	vect_dot(plane.n, vect_cross(vect_diff(tr->pt_c, tr->pt_b),
		 			vect_diff(ray_object, tr->pt_b))) >= 0.0
         && vect_dot(plane.n, vect_cross(vect_diff(tr->pt_a, tr->pt_c),
		 			vect_diff(ray_object, tr->pt_c))) >= 0.0)
            return (t);
    }
    return(-1.0);
}

/*
double   tr_intersect2(t_ray *ray, t_triangle *tr)
{
	t_vect		hit;
	t_plane     plane;
	double		t;

	plane.n = vect_cross(vect_diff(tr->pt_b, tr->pt_a),
						vect_diff(tr->pt_c, tr->pt_a));
	plane.n = vect_unit(plane.n);
	tr->normal = plane.n;
	plane.p = tr->pt_a;
	if ((t = pl_intersect(ray, &plane)) >= 0)
	{
		hit = vect_const_prod(t, ray->dir);
		hit = vect_sum(ray->origin, hit);
		if (vect_dot(plane.n, vect_cross(vect_diff(tr->pt_b, tr->pt_a),
										vect_diff(hit, tr->pt_a))) >= 0 &&
			vect_dot(plane.n, vect_cross(vect_diff(tr->pt_c, tr->pt_b),
										vect_diff(hit, tr->pt_b))) >= 0 &&
			vect_dot(plane.n, vect_cross(vect_diff(tr->pt_a, tr->pt_c),
										vect_diff(hit, tr->pt_c))) >= 0)
			return (t);
	}
	return(-1);
}

*/

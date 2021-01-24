/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vect_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:09:02 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/24 08:37:00 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECT_MATH_H
# define T_VECT_MATH_H

# include <math.h>

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_mat3x3
{
	t_vect		line1;
	t_vect		line2;
	t_vect		line3;
}				t_mat3x3;

typedef struct	s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct	s_solution
{
	double		t1;
	double		t2;
}				t_solution;

typedef struct		s_cylinder
{
	t_vect			origin;
	t_vect			axis;
	double			height;
	double			radius;
	t_vect			color_vect;
	int				color;
}					t_cylinder;

typedef struct		s_ray
{
	t_vect			origin;
	t_vect			screen;
	t_vect			dir;
	t_vect			cam_up;
}					t_ray;

t_vect			vect_diff(t_vect u, t_vect v);
t_vect			vect_sum(t_vect u, t_vect v);
double			vect_dot(t_vect u, t_vect v);
double			vect_norm(t_vect v);
t_vect			vect_unit(t_vect v);
t_vect  		vect_prod(t_vect u, t_vect v);
t_vect			vect_const_sum(double cst, t_vect v);
t_vect			vect_const_prod(double cst, t_vect v);
int     		is_vect_equal(t_vect u, t_vect v);
t_vect  		vect_cross(t_vect u, t_vect v);
t_vect			itovect(int color);
int				vectoi(t_vect vect);
int				is_vect_null(t_vect vect);
t_vect			mat_vect_prod(t_mat3x3	mat, t_vect	v);
t_solution		solve_rt_quadratic(t_coeff *coeff);
double			limit_cylinder(t_coeff *coeff, t_ray *ray,
								t_cylinder *cy);

#endif
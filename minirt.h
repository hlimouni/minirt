/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:37:09 by hlimouni          #+#    #+#             */
/*   Updated: 2020/10/17 11:39:12 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define TO_RAD(DEG) ((DEG) * M_PI / 180.0)
# define WIDTH 1000
# define HEIGHT 700

typedef	struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_mat44
{
	float			element[4][4];
}					t_mat44;

/*
** camera List that contains it's "coordinate vector" ==> "c" "The look at direction" ==>
**     "l", the "field of view" ==> fov
*/

typedef	struct		s_cam
{
	t_vect			c;
	t_vect			l;
	float			fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_plane
{
	t_vect			p;
	t_vect			n;
	int				color;
}					t_plane;


typedef struct		s_light
{
	t_vect			l;
	float			intensity;
	int				color;
}					t_light;

typedef struct		s_ray
{
	t_vect			origin;
	t_vect			screen;
	t_vect			hit;
	float			t;
}					t_ray;


/*
** s_object structs will contain the object's unique propreties
*/

typedef struct		s_amb
{
	float			intensity;
	int				color;
}					t_amb;

typedef	struct		s_sphere
{
	t_vect			o;
	float			d;
	int				color;
}					t_sphere;

typedef	struct		s_resolution
{
	float			width;
	float			height;
}					t_resolution;

t_vect				cam_ray_build(int i, int j, t_cam *cam,
						float width, float height);
float				sp_intersect(t_vect ray, t_cam *cam, t_sphere sp);
float				pl_intersect(t_vect ray, t_cam *cam, t_plane plane);
t_vect				vect_diff(t_vect u, t_vect v);
t_vect				vect_sum(t_vect u, t_vect v);
float				vect_dot(t_vect u, t_vect v);
float				vect_norm(t_vect v);
t_vect				vect_unit(t_vect v);
t_vect  			vect_prod(t_vect u, t_vect v);
t_vect				vect_const_sum(float cst, t_vect v);
t_vect				vect_const_prod(float cst, t_vect v);
int					sp_shading(float t, t_light *light,
					t_cam *cam, t_sphere sp, t_amb amb, t_vect ray_screen);
int					pl_shading(float t, t_light *light, t_cam *cam, t_plane pl,
					t_amb amb, t_vect ray_screen);

#endif

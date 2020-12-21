/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:37:09 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/20 19:17:16 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
//# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

# define A_BIG_VALUE 1e14
# define NEGATIVE_VALUE -1

// # define RT_TYPES_NUM 8
// //# define RT_ELEMS_COUNT 10
// # define SQ_PARAMS 5
// # define SP_PARAMS 4
// # define TR_PARAMS 5
// # define CY_PARAMS 5
// # define PL_PARAMS 4
// # define TRAN_PARAMS 3
// # define ROT_PARAMS 5

enum	e_rt_file_param_types
{
	ID_type,
	vector_type,
	decimal_type,
	udecimal_type,
	rgb_type,
	ratio_type,
	angle_type,
	uint_type,
	rt_types_num
};
// typedef struct	s_element_info
// {
// 	int		*params;
// 	t_square	square;
// }				t_element_info;

enum	e_rt_file_elements
{
	rt_camera,
	rt_ambiant,
	rt_resolution,
	rt_light,
	rt_square,
	rt_triangle,
	rt_sphere,
	rt_cylinder,
	rt_plane,
	rt_translation,
	rt_rotation,
	rt_elems_num
};

enum	e_ambiant_parameters
{
	amb_ID,
	amb_ratio,
	amb_color,
	amb_params_num
};

enum	e_camera_parameters
{
	c_ID,
	c_position,
	c_orientation,
	c_fov,
	c_params_num
};

enum	e_light_parameters
{
	l_ID,
	l_position,
	l_bright,
	l_color,
	l_params_num
};

enum 	e_resolution_parameters
{
	res_ID,
	res_width,
	res_height,
	res_params_num
};

enum	e_sphere_parameters
{
	sp_ID,
	sp_center,
	sp_radius,
	sp_color,
	sp_params_num
};

enum	e_square_parameters
{
	sq_ID,
	sq_position,
	sq_normal,
	sq_side,
	sq_color,
	sq_params_num
};

enum	e_plane_parameters
{
	pl_ID,
	pl_position,
	pl_normal,
	pl_color,
	pl_params_num
};

enum	e_cylinder_parameters
{
	cy_ID,
	cy_position,
	cy_axis,
	cy_diameter,
	cy_height,
	cy_color,
	cy_params_num
};

enum	e_triangle_parameters
{
	tr_ID,
	tr_1st_pnt,
	tr_2nd_pnt,
	tr_3rd_pnt,
	tr_color,
	tr_params_num
};

enum	e_translation_parameters
{
	tran_ID,
	tran_object,
	tran_vect,
	tran_params_num
};

enum	e_rotation_parameters
{
	rot_ID,
	rot_object,
	rot_pitch,
	rot_yaw,
	rot_roll,
	rot_params_num
};

typedef	int* (*t_info_set) (void);
typedef	int (*t_typechecker)(char *);





typedef struct	s_scene
{
	/* scene data */
}				t_scene;


typedef	struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_mat3x3
{
	t_vect			line1;
	t_vect			line2;
	t_vect			line3;
}					t_mat3x3;

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
	t_vect			up;
	float			fov;
}					t_cam;

typedef struct		s_plane
{
	t_vect			p;
	t_vect			n;
	int				color;
}					t_plane;

typedef struct		s_square
{
	t_vect			origin;
	t_vect			normal;
	float			side;
	int				color;
}					t_square;

typedef struct 		s_triangle
{
	t_vect			A;
	t_vect			B;
	t_vect			C;
	t_vect			noraml;
	int				color;
}					t_triangle;


typedef struct		s_cylinder
{
	t_vect			origin;
	t_vect			axis;
	float			height;
	float			diameter;
	int				color;
}					t_cylinder;


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
t_vect				cam_ray_build2(int i, int j, t_cam *cam,
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
int     			is_vect_equal(t_vect u, t_vect v);
t_vect  			vect_cross(t_vect u, t_vect v);
float   			sq_intersect(t_vect ray_screen, t_cam *cam, t_square square);
float  				cy_intersect(t_vect ray_screen, t_cam *cam, t_cylinder cy);
float   			tr_intersect(t_vect ray_screen, t_cam *cam, t_triangle *tr);
int					cy_shading(float t, t_light *light, t_cam *cam, t_cylinder cy,
		t_amb amb, t_vect ray_screen);
t_vect				itovect(int color);

#endif

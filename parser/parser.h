/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:48:49 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 19:39:18 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../t_vect_math/t_vect_math.h"
# define BUFFER_SIZE 20
# define A_BIG_VALUE 1e14
# define NEGATIVE_VALUE -1
# include <fcntl.h>
# include <stdlib.h>

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
	yaw_type,
	pitch_type,
	roll_type,
	rt_types_num
};

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

enum	e_errors
{
	nofile_err = -255,
	open_err,
	read_err,
	many_args_err,
	format_err,
	wrong_arg_err,
	alloc_err,
	type_err,
	num_params_err,
	multicall_err,
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

enum	e_resolution_parameters
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
	sp_diameter,
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
	cy_params_num,
	max_params
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
	rot_yaw,
	rot_pitch,
	rot_roll,
	rot_params_num
};

typedef	struct		s_cam
{
	t_vect			c;
	t_vect			l;
	t_vect			up;
	double			fov;
}					t_cam;

typedef struct		s_plane
{
	t_vect			p;
	t_vect			n;
	int				color;
	t_vect			color_vect;
}					t_plane;

typedef struct		s_square
{
	t_vect			origin;
	t_vect			normal;
	t_vect			u;
	t_vect			v;
	double			side;
	int				color;
	t_vect			color_vect;
}					t_square;

typedef struct 		s_triangle
{
	t_vect			pt_a;
	t_vect			pt_b;
	t_vect			pt_c;
	t_vect			normal;
	t_vect			color_vect;
	int				color;
}					t_triangle;


typedef struct		s_cylinder
{
	t_vect			origin;
	t_vect			axis;
	double			height;
	double			radius;
	t_vect			color_vect;
	int				color;
}					t_cylinder;


typedef struct		s_light
{
	t_vect			l;
	double			intensity;
	t_vect			coeff;
	t_vect			color_vect;
	int				color;
}					t_light;

typedef struct		s_ray
{
	t_vect			origin;
	t_vect			screen;
	t_vect			dir;
}					t_ray;

typedef struct		s_amb
{
	double			intensity;
	t_vect			color_vect;
	int				color;
	t_vect			coeff;
}					t_amb;

typedef	struct		s_sphere
{
	t_vect			o;
	double			r;
	t_vect			color_vect;
	int				color;
}					t_sphere;

typedef	struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_translation
{
	int				obj_ID;
	t_vect			vector;
}					t_translation;

typedef struct		s_rotation
{
	int				obj_ID;
	double			yaw;
	double			pitch;
	double			roll;
}					t_rotation;

typedef struct		s_scene
{
	t_resolution	*res;
	t_amb			*amb;
	t_list			*cams;
	t_list			*lights;
	t_list			*objs;
}				t_scene;

typedef int			(*t_elem_push)(char **, t_scene *);
typedef	int			(*t_typechecker)(char *);

int					get_next_line(int fd, char **line);
double				str_tof(char *str);
t_vect 				str_to_vect(char *str);
int					is_str_float(char *str);
int					is_str_ufloat(char *str);
int					is_str_ratio(char *str);
int					is_str_angle(char *str);
int					is_str_yaw(char *str);
int					is_str_pitch(char *str);
int					is_str(char *str, int type);
int					rt_elemlen(char *arr);
int					rt_square_push(char **splt_line, t_scene *scene);
int					rt_triangle_push(char **splt_line, t_scene *scene);
int					rt_sphere_push(char **splt_line, t_scene *scene);
int					rt_cylinder_push(char **splt_line, t_scene *scene);
int					rt_plane_push(char **splt_line, t_scene *scene);
int					add_elem_to_scene(t_scene *scene, char **splt_line);
void				rt_free_scene(t_scene *scene);
void				rt_exit(int rt_error_num, int line, int param, void *ptrs[]);

#endif
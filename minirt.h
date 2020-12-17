/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:37:09 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/17 22:16:44 by hlimouni         ###   ########.fr       */
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

# define RT_TYPES_NUM 8
# define SQ_PARAMS 5
# define SP_PARAMS 4
# define TR_PARAMS 5
# define CY_PARAMS 5
# define PL_PARAMS 4
# define TRAN_PARAMS 3
# define ROT_PARAMS 5


enum	e_minirt_elements
{
	rt_camera,
	rt_ambiant,
	rt_resolution,
	rt_square,
	rt_trinagle,
	rt_sphere,
	rt_cylinder,
	rt_plane,
	rt_translation,
	rt_rotation

};

typedef struct	s_element_info
{
	int		*params;
	t_square	square;
}		t_element_info;

enum	e_square_parameters
{
	sq_ID,
	sq_position,
	sq_normal,
	sq_side,
	sq_color	
};

enum	e_minirt_elements_parameter_types
{
	ID_type,
	vector_type,
	decimal_type,
	udecimal_type,
	rgb_type,
	ratio_type,
	angle_type,
	uint_type	
};

int	is_str_ID(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "sq") == 0)
		return (rt_square);
	if (ft_strcmp(str, "A") == 0)
		return (rt_ambiant);
	if (ft_strcmp(str, "R") == 0)
		return (rt_resolution);
	if (ft_strcmp(str, "c") == 0)
		return (rt_camera);
	if (ft_strcmp(str, "tr") == 0)
		return (rt_triangle);
	if (ft_strcmp(str, "pl") == 0)
		return (rt_plane);
	if (ft_strcmp(str, "sp") == 0)
		return (rt_sphere);
	if (ft_strcmp(str, "cy") == 0)
		return (rt_cylinder);
	if (ft_strcmp(str, "tran") == 0)
		return (rt_translation);
	if (ft_strcmp(str, "rot") == 0)
		return (rt_rotation);
	return (0);
}

int	*square_info_set(void)
{
	int	*sq_info;

	square_info = (int *)malloc(sizeof(int) * (SQ_PARAMS + 1));
	square_info[sq_ID] = rt_square;
	square_info[sq_position] = vector_type;
	square_info[sq_normal] = vector_type;
	square_info[sq_side] = udecimal_type;
	square_info[sq_color] = rgb_type;
	square_info[SQ_PARAMS] = -1;
}

void	free_info_arr(int ***info)
{
	int	i;

	i = 0;
	while (i < 
/*
void    free_2d_array(char ***arr)
{
        int             i;

        i = 0;
        while ((*arr)[i])
        {
                free((*arr)[i]);
                (*arr)[i] = NULL;
                i++;
        }
        free(*arr);
        *arr = NULL;
}
*/
}

int	element_len(int	*element)
{
	int	i;

	i = 0;
	while (element[i] >= 0)
		i++;
	return (i);
}


void elem_info_set(void)
{
	t_element_info	square_info;
	t_element_info	sphere_info;
	t_element_info	triangle_info;
	t_element_info	cylinder_info;
	t_element_info	plane_info;
	t_element_info	tran_info;
	t_element_info	rot_info;
	int		*info[RT_ELEMS];
	int		square[SQ_PARAMS + 1];
	int		sphere[SP_PARAMS + 1];
	int		triangle[TR_PARAMS + 1];
	int		cylinder[CY_PARAMS + 1];
	int		plane[PL_PARAMS + 1];
	int		tran[TR_PARAMS + 1];
	int		rot[ROT_PARAMS + 1];	
	int		camera[C_PARAMS + 1];
	int		res[RES_PARAMS + 1];

	square[sq_ID] = rt_square;
	square[sq_position] = vector_type;
	square[sq_normal] = vector_type;
	square[sq_side] = udecimal_type;
	square[sq_color] = rgb_type;
	square[SQ_PARAMS] = -1;
	info[rt_square] = square;
	square_info.params= square;
	sphere[sp_ID] = rt_sphere;
	sphere[sp_center] = vector_type;
	sphere[sp_radius] = udecimal_type;
	sphere[sp_color] = rgb_type;
	sphere_info.params = sphere;
	triangle[tr_ID] = rt_triangle;
	triangle[tr_1st_pnt] = vector_type;
	triangle[tr_2nd_pnt] = vector_type;
	triangle[tr_3rd_pnt] = vector_type;
	triangle[tr_color] = rgb_type;
	triangle_info.params = triangle;
	cylinder[cy_
}

typedef	int (t_typechecker)(char *);



int	is_str(char *str, int rt_type)
{
	t_typechecker	typechecker_arr[RT_TYPES_NUM];

	typechecker_arr[rt_ID] = is_str_ID;
	typechecker_arr[rt_vector] = is_str_vector;
	typechecker_arr[rt_float] = is_str_float;
	typechecker_arr[rt_rgb] = is_str_rgb;
	typechecker_arr[rt_ratio] = is_str_ratio;
	typechecker_arr[rt_angle] = is_str_angle;
	typechecker_arr[rt_positive_int] = is_str_uint;;
	return (typechecker_arr[rt_type](str));
}

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

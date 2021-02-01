/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:37:09 by hlimouni          #+#    #+#             */
/*   Updated: 2021/02/01 18:18:50 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "parser/parser.h"
# include "mlx/mlx.h"
# define BIAS 1e-5
# define K_SPACE 49
# define K_ESC 53
# define E_DESTROY 17
# define E_KEY_PRESS 2
# define AMB_C M_1_PI
# define DIFU_C M_1_PI
# define SPEC_C	140
# define SHINE 15

enum				e_pixel_coordinates
{
	i_pxl,
	j_pxl
};

typedef struct		s_mlibx
{
	void			*ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	int				line_len;
	int				bbp;
	int				endian;
}					t_mlibx;

typedef struct		s_hit
{
	double			t;
	t_list			*obj;
    t_vect          ray_obj;
	t_vect			normal;
	t_vect			view;
	t_vect			color;
	t_vect			to_light;
	t_vect			cam_up;
	double			surface_illumi;
	int				pxl_color;
}					t_hit;

typedef struct		s_rt_data	
{
	t_mlibx			*mlx;
	t_scene			*scene;
}					t_rt_data;

void				cam_ray_build(int pxl[], t_cam *cam,
							t_resolution *res, t_ray *ray);
void				set_base_for_squares(t_cam *cam, t_list *list);
void				rt_free_scene(t_scene *scene);
int     			open_rt_file(int ac, char *av[]);
void				rt_parse(int fd, t_scene *scene);
void				rt_scene_initialize(t_scene *scene);
int					pixel_shade(t_hit *hit, t_scene *scene);
void				rt_image_create(t_scene *scene, t_mlibx *mlx);
void				display_rt_image(t_scene *scene, t_mlibx *mlx);
void				ray_intersect(t_ray *ray, t_list *obj_node,
							t_hit *hit);
double				sq_intersect(t_ray *ray, t_square *sq);
double				sp_intersect(t_ray *ray, t_sphere *sphere);
double				pl_intersect(t_ray *ray, t_plane *plane);
double				cy_intersect(t_ray *ray, t_cylinder *cy);
double				tr_intersect(t_ray *ray, t_triangle *tr);
void				rt_image_clear(t_scene *scene, int *img_data);
double				one_obj_intersect(t_ray *ray, t_list *obj_node);

#endif

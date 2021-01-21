/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:48:49 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/20 18:59:15 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:00:31 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:34:30 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	info_arr_set(int elem, char info[])
{
	char			**data;

	ft_memset(info, -1, cy_params_num + 1);
	data = (char*[])
	{
		(char[]){rt_camera, vector_type, vector_type, angle_type, -1},
		(char[]){rt_ambiant, ratio_type, rgb_type, -1},
		(char[]){rt_resolution, uint_type, uint_type, -1},
		(char[]){rt_light, vector_type, ratio_type, rgb_type, -1},
		(char[]){rt_square,
			vector_type, vector_type, udecimal_type, rgb_type, -1},
		(char[]){rt_triangle,
			vector_type, vector_type, vector_type, rgb_type, -1},
		(char[]){rt_sphere, vector_type, udecimal_type, rgb_type, -1},
		(char[]){rt_cylinder, vector_type, vector_type, udecimal_type,
			udecimal_type, rgb_type, -1},
		(char[]){rt_plane, vector_type, vector_type, rgb_type, -1},
		(char[]){rt_translation, ID_type, vector_type, -1},
		(char[]){rt_rotation, ID_type, yaw_type, pitch_type, roll_type, -1}
	};
	ft_memmove(info, data[elem], rt_elemlen(data[elem]));
}

static int		is_line_empty(char **line, int	*line_ct)
{
	int	ret;

	if (ft_strcmp(*line, "") == 0 || *(ft_skip_spaces(*line)) == '#')
	{
		ft_free_null((void **)line);
		(*line_ct)++;
		ret = 1;
	}
	else
		ret = 0;
	return (ret);
}

static char		**check_line(char **line, int line_ct)
{
	char	**splitd_line;
	char	info[cy_params_num + 1];
	void	**ptrs;
	int		param;
	int		elem;

	ptrs = (void *[]){line, &splitd_line};
	if (!(splitd_line = ft_split(*line, ' ')))
		rt_exit(alloc_err, line_ct, param, ptrs);
	if ((elem = is_str(splitd_line[0], ID_type)) < 0)
		rt_exit(type_err, line_ct, ID_type, ptrs);
	info_arr_set(elem, info);
	param = 1;
	while (splitd_line[param] && info[param] != -1)
	{
		if (is_str(splitd_line[param], info[param]) < 1)
			rt_exit(type_err, line_ct, param, ptrs);
		param++;
	}
	if (splitd_line[param] != NULL || info[param] != -1)
		rt_exit(num_params_err, line_ct, param, ptrs);
	return (splitd_line);
}

static void	check_missing_elems(t_scene *scene)
{
	if (scene->res == NULL)
		ft_putstr_fd("Error\nminiRT: Resolution is not specified.\n", 2);
	if (scene->amb == NULL)
		ft_putstr_fd("Error\nminiRT: Ambiant is not specified.\n", 2);
	if (scene->cams == NULL)
		ft_putstr_fd("Error\nminiRT: No camera specified.\n", 2);
	if (!(scene->res) || !(scene->amb) || !(scene->cams))
	{
		rt_free_scene(scene);
		exit(1);
	}
}

void	rt_parse(int fd, t_scene *scene)
{
	char	*line;
	int		line_ct;
	void	**ptrs;
	int		ret;
	char	**splitd_line;

	line = NULL;
	line_ct = 1;
	ptrs = (void *[]) {&line, &splitd_line};
	while (get_next_line(fd, &line) > 0)
	{
		if (is_line_empty(&line, &line_ct))
			continue ;
		splitd_line = check_line(&line, line_ct);
		if ((ret = add_elem_to_scene(scene, splitd_line)) < 0)
			rt_exit(ret == -1 ? multicall_err : alloc_err, line_ct, 0, ptrs);
		free_2d_array(&splitd_line);
		ft_free_null((void **)&line);
		line_ct++;
	}
	check_missing_elems(scene);
}

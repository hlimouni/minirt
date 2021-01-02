/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:03:00 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/02 17:13:10 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// error:
// parameter in line "3" is not a vector.

void	put_type_stder(int type)
{
	type == ID_type ? ft_putstr_fd("an identifier.\n", 2) : 0;
	type == vector_type ? ft_putstr_fd("a vector.\n", 2) : 0;
	type == decimal_type ? ft_putstr_fd("a decimal.\n", 2) : 0;
	type == udecimal_type ? ft_putstr_fd("a positive decimal.\n", 2) : 0;
	type == rgb_type ? ft_putstr_fd("a color.\n", 2) : 0;
	type == ratio_type ? ft_putstr_fd("a ratio.\n", 2) : 0;
	type == angle_type ? ft_putstr_fd("an angle.\n", 2) : 0;
	type == uint_type ? ft_putstr_fd("a positive integer.\n", 2) : 0;
}

void	rt_stder_type_msg(int line_ct, int type)
{
	ft_putstr_fd("Error\nminiRT: Parameter in line ");
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" is not ", 2);
	put_type_stder(type);
	exit(1);
}

void	rt_stder_num_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Wrong number of parameters in line ");
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	free_aloc_prev(char **line, int ***info, char ***splitd_line)
{
	free_2d_array(splitd_line);
	ft_free_null((void **)line);
	free_info_arr(info);
}

void	rt_errnum_exit(int line_ct, char **line, char ***info, char ***splitd_line)
{
	free_2d_array(splitd_line);
	free(*line);
	free_info_arr(info);
	rt_stder_num_msg(line_ct);	
}

void	rt_erraloc_exit(char **line, char ***info, char ***splitd_line)
{
	free_2d_array(splitd_line);
	free_2d_array(info);
	ft_free_null((void **)line);
	ft_putstr_fd("Error\nMalloc: failded to allocate memory.\n");
	exit(1);
}

void	rt_errtype_exit(int line_ct, int type, char **line, int ***info, char ***splitd_line)
{
	free_2d_array(splitd_line);
	free(*line);
	free_info_arr(info);
	rt_stder_type_msg(line_ct);
}

void	rt_errcall_exit(int line_ct, char **line, int ***info, char ***splitd_line)
{
	free_2d_array(splitd_line);
	free(*line);
	free_info_arr(info);
	ft_putstr_fd("Error\nminiRT: Element in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" should not be called more than once.\n", 2);
	exit(1);
}

int		is_line_empty(char **line, int	*line_ct)
{
	int	ret;

	if (ft_strcmp(*line, "") == 0 || **line == '#')
	{
		ft_free_null((void **)line);
		(*line_ct)++;
		ret = 1;
	}
	else
		ret = 0;
}

void	check_missing_elems(t_scene *scene)
{
	if (scene->res == NULL)
	{
		ft_putstr_fd("Error\nminiRT: Resolution is not specified.\n", 2);
		exit(1);
	}
	if (scene->amb == NULL)
	{
		ft_putstr_fd("Error\nminiRT: Ambiant is not specified.\n"), 2);
		exit(1);
	}
	if (scene->cams == NULL)
	{
		ft_putstr_fd("Error\nminiRT: Camera is not specified.\n", 2);
		exit(1);
	}
	
}

void	rt_parse(int fd, t_scene *scene)
{
	char	*line;
	int		line_ct;
	int		elem;
	int		elem_params;
	int		ret;
	int		param;
	char	**splitd_line;
	char	**info;

	info = array_info_set2();
	line_ct = 1;
	while (get_next_line(fd, &line) > 0)
	{
		// if (!(splitd_line = ft_split(line, ' ')))
		// {
		// 	free_2d_array(&splitd_line);
		// 	ft_free_null((void *)&line);
		// 	continue ;
		// }
		if (is_line_empty(&line, &line_ct))
			continue ;
		if (!(splitd_line = ft_split(line, ' ')))
			rt_erraloc_exit(&line, &info, &splitd_line);
		if ((elem = is_str(splitd_line[0], ID_type) < 0)
			rt_errtype_exit(line_ct, ID_type, &line, &info, &splitd_line);
		param = 1;
		while (splitd_line[param] && info[elem][param] >= 0)
		{
			if (!is_str(splitd_line[param], info[elem][param]))
				rt_errtype_exit(line_ct, param, &line, &info, &splitd_line);
			param++;
		}
		if (splitd_line[param] != NULL || info[elem][param] != -1)
			rt_errnum_exit(line_ct, &line, &info, &splitd_line);
		if ((ret = add_elem_to_scene(elem, scene, splitd_line)) < 0)
		{
			if (ret == 0)
				rt_erraloc_exit(&line, &info, &splitd_line);
			if (ret == -1)
				rt_errcall_exit(line_ct, &line, &info, &splitd_line);
		}
		free_2d_array(&splitd_line);
		ft_free_null(&(void *)line);
		line_ct++;
	}
	free_2d_array(&info);
	check_missing_elems(scene);
}

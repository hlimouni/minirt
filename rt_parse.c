/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:03:00 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/28 16:02:18 by hlimouni         ###   ########.fr       */
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

void	free_aloc_prev(char **line, int ***info, char ***line_arr)
{
	free_2d_array(line_arr);
	ft_free_null((void **)line);
	free_info_arr(info);
}

void	rt_errnum_exit(int line_ct, char **line, int ***info, char ***line_arr)
{
	free_2d_array(line_arr);
	free(*line);
	free_info_arr(info);
	rt_stder_num_msg(line_ct);	
}

void	rt_errtype_exit(int line_ct, int type, char **line, int ***info, char ***line_arr)
{
	free_2d_array(line_arr);
	free(*line);
	free_info_arr(info);
	rt_stder_type_msg(line_ct);
}

void	rt_parse(int fd, t_scene *scene)
{
	char	*line;
	int		line_ct;
	int		elem;
	int		elem_params;
	int		param;
	char	**line_arr;
	int		**elems_info;

	elems_info = array_info_set();
	line_ct = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line_arr = ft_split(line, ' ')))
		{
			free_2d_array(&line_arr);
			free(line);
			continue ;
		}
		param = 0;
		if ((elem = is_str(line_arr[param], ID_type) < 0)
			rt_errtype_exit(line_ct, param, &line, &elems_info, &line_arr);
		param++;
		while (line_arr[param] && elems_info[elem][param] >= 0)
		{
			if (!is_str(line_arr[param], elems_info[elem][param]))
				rt_errtype_exit(line_ct, param, &line, &elems_info, &line_arr);
			param++;
		}
		if (line_arr[param] != NULL || elems_info[elem][param] != -1)
			rt_errnum_exit(line_ct, &line, &elems_info, &line_arr);
		add_elem_to_scene(elem, scene, line_arr);
		free_2d_array(&line_arr);
		free(line);
		line_ct++;
	}
	free_info_arr(&elems_info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:03:00 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/24 18:43:46 by hlimouni         ###   ########.fr       */
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

void	rt_stder_type_msg(int line, int type)
{
	ft_putstr_fd("Error\nminiRT: Parameter in line ");
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" is not ", 2);
	put_type_stder(type);
	exit(1);
}

void	rt_free_exit(int line_ct, int type, char **line, int ***info, char ***line_arr)
{
	free_2d_array(line_arr);
	free(*line);
	free_info_arr(info);
	rt_stder_type_msg(line_ct + 1, type);
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
	line_ct = 0;
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
			rt_free_exit(line_ct, ID_type, &line, &elems_info, &line_arr);
		// {
		// 	free_2d_array(&line_arr);
		// 	free(line);
		// 	free_2d_array(&elems_info);
		// 	rt_stder_type_msg(line_ct + 1, ID_type);
		// }
		param++;
		while (is_str(line_arr[param], elems_info[elem][param]))
		{
			
		}
		is_str(arr[line_ct]);
		free(line);
		line_ct++;
	}
	
}
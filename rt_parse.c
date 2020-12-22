/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:03:00 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/22 20:23:35 by hlimouni         ###   ########.fr       */
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

void	rt_stder_msg(int line, int type)
{
	ft_putstr_fd("Error\nminiRT: Parameter in line ");
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" is not ", 2);
	put_type_stder(type);
	exit(1);
}

t_scene		rt_parse(int fd)
{
	char	*line;
	int		line_ct;
	int		elem;
	int		param;
	char	**line_arr;
	char	**elems_info;

	elems_info = array_info_set();
	line_ct = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line_arr = ft_split(line, ' ')))
		{
			free_2d_array(&line_arr);
			continue ;
		}
		param = 0;
		if ((elem = is_str(line_arr[param], ID_type) < 0)
		{
			free_2d_array(&line_arr);
			free(line);
			rt_stder_msg(line_ct + 1, ID_type);
			param++;
		}
		while (is_str(line_arr[param], elems_info[elem][param]))
		{
			
		}
		is_str(arr[line_ct]);
		free(line);
		line_ct++;
	}
	
}
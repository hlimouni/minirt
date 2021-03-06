/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_rt_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:03:00 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:22:37 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// error:
// parameter in line "3" is not a vector.

void	put_type_stder(int type)
{
	type == ID_type ? ft_putstr_fd("a minirt identifier.\n", 2) : 0;
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

void	type_err_msg(int line_ct, int type)
{
	ft_putstr_fd("Error\nminiRT: Parameter in line ");
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" is not ", 2);
	put_type_stder(type);
}

void	rt_stder_num_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Wrong number of parameters in line ");
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	num_err_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Wrong number of parameters in line ");
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(".\n", 2);
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

void	multicall_err_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Element in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" should not be called more than once.\n", 2);
}

int		is_line_empty(char **line, int	*line_ct)
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
}

void	check_missing_elems(t_scene *scene)
{
	if (scene->res == NULL)
		ft_putstr_fd("Error\nminiRT: Resolution is not specified.\n", 2);
	if (scene->amb == NULL)
		ft_putstr_fd("Error\nminiRT: Ambiant is not specified.\n"), 2);
	if (scene->cams == NULL)
		ft_putstr_fd("Error\nminiRT: No camera specified.\n", 2);
	if (!(scene->res) || !(scene->amb) || !(scene->cams))
	{
		rt_free_scene(scene);
		exit(1);
	}
}

void	free_ptrs(void *ptrs[])
{
	ft_free_null((void **)ptrs[0]);
	free_2d_array((char ***)ptrs[1]);
}

void	rt_exit(int rt_error_num, int line, int param, void *ptrs[])
{
	free_ptrs(ptrs);
	if (rt_error_num == alloc_err)
		ft_putstr_fd("Error\nMalloc: failed to allocate memory.\n", 2);
	else if (rt_error_num == type_err)
		type_err_msg(line, param);
	else if (rt_error_num == nofile_err)
		ft_putstr_fd("Error\nminiRT: No input file.\n", 2);
	else if (rt_error_num == many_args_err)
		ft_putstr_fd("Error\nminiRT: Too many arguments.\n", 2);
	else if (rt_error_num == format_err)
		ft_putstr_fd("Error\nminiRT: Wrong file format.\n", 2);
	else if (rt_error_num == wrong_arg_err)
		ft_putstr_fd("Error\nminiRT: Wrong argument.\n", 2);
	else if (rt_error_num == num_params_err)
		num_err_msg(line);
	else if (rt_error_num == multicall_err)
		multicall_err_msg(line);
	exit(1);
}

void	rt_free_scene(t_scene *scene)
{
	ft_free_null(&(void *)(scene->amb));
	ft_free_null(&(void *)(scene->res));
	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->objs), free);
}

char		**check_line(char **line, int line_ct)
{
	char	**splitd_line;
	char	info[cy_params_num + 1];
	void	**ptrs;
	int		param;
	int		elem;

	ptrs = (void *[]){line, &splitd_line};
	if (!(splitd_line = ft_split(*line, ' ')))
		rt_exit(alloc_err, line_ct, param, ptrs);
	if ((elem = is_str(splitd_line[0], ID_type) < 0)
		rt_exit(type_err, line_ct, ID_type, ptrs);
	info_arr_set3(elem, info);
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

		// if (!(splitd_line = ft_split(line, ' ')))
		// 	rt_erraloc_exit(&line, &info, &splitd_line);
		// if ((elem = is_str(splitd_line[0], ID_type) < 0)
		// 	rt_errtype_exit(line_ct, ID_type, &line, &info, &splitd_line);
		// param = 1;
		// while (splitd_line[param] && info[elem][param] >= 0)
		// {
		// 	if (!is_str(splitd_line[param], info[elem][param]))
		// 		rt_errtype_exit(line_ct, param, &line, &info, &splitd_line);
		// 	param++;
		// }
		// if (splitd_line[param] != NULL || info[elem][param] != -1)
		// 	rt_errnum_exit(line_ct, &line, &info, &splitd_line);
			// if (ret == 0)
			// 	rt_erraloc_exit(&line, &info, &splitd_line);
			// if (ret == -1)
			// 	rt_errcall_exit(line_ct, &line, &info, &splitd_line);
void	rt_parse2(int fd, t_scene *scene)
{
	char	*line;
	int		line_ct;
	void	**ptrs;
	int		ret;
	char	**splitd_line;

	line = NULL;
	line_ct = 1;
	ptrs = (void *[]) {&line, &splitd_line, NULL}
	while (get_next_line(fd, &line) > 0)
	{
		if (is_line_empty(&line, &line_ct))
			continue ;
		splitd_line = check_line(&line, line_ct);
		if ((ret = add_elem_to_scene(scene, splitd_line)) < 0)
			rt_exit(ret == -1 ? multicall_err : alloc_err, line_ct, 0, ptrs);
		free_2d_array(&splitd_line);
		ft_free_null(&(void *)line);
		line_ct++;
	}
	check_missing_elems(scene);
}

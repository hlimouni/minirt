/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:33:44 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 12:32:50 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_ptrs(void *ptrs[])
{
	if (!ptrs)
		return ;
	ft_free_null((void **)ptrs[0]);
	free_2d_array((char ***)ptrs[1]);
}

static void	type_err_msg(int line_ct, int type)
{
	ft_putstr_fd("Error\nminiRT: Parameter in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" is not ", 2);
	if (type == ID_type)
		ft_putstr_fd("a minirt identifier.\n", 2);
	else if (type == vector_type)
		ft_putstr_fd("a vector.\n", 2);
	else if (type == decimal_type)
		ft_putstr_fd("a decimal.\n", 2);
	else if (type == udecimal_type)
		ft_putstr_fd("a positive decimal.\n", 2);
	else if (type == rgb_type)
		ft_putstr_fd("a color.\n", 2);
	else if (type == ratio_type)
		ft_putstr_fd("a ratio.\n", 2);
	else if (type == angle_type)
		ft_putstr_fd("an angle.\n", 2);
	else if (type == uint_type)
		ft_putstr_fd("a positive integer.\n", 2);
	exit(1);
}

static void	num_err_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Wrong number of parameters in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(".\n", 2);
}

static void	multicall_err_msg(int line_ct)
{
	ft_putstr_fd("Error\nminiRT: Element in line ", 2);
	ft_putnbr_fd(line_ct, 2);
	ft_putstr_fd(" should not be called more than once.\n", 2);
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
	else if (rt_error_num == open_err)
		perror("Open");
	else if (rt_error_num == read_err)
		perror("Read");
	exit(1);
}
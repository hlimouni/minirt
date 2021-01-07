/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 09:07:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/07 10:43:09 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     open_rt_file(int ac, char *av[])
{
    int     fd;

    if (ac == 1)
        rt_exit(nofile_err, 0, 0, NULL);
    if (ac > 3)
        rt_exit(many_args_err, 0, 0, NULL);
    if ((fd = open(av[1], O_RDONLY)) < 0)
		rt_exit(open_err, 0, 0, NULL);
	if (read(fd, NULL, 0) < 0)
		rt_exit(read_err, 0, 0, NULL);
    if (!ft_strchr(av[1], '.') || ft_strcmp(ft_strrchr(av[1], '.'), ".rt"))
        rt_exit(format_err, 0, 0, NULL);
    if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
        rt_exit(wrong_arg_err, 0, 0, NULL);
    return (fd);
}
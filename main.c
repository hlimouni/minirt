/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:08:03 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/02 20:57:19 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char* av[])
{
    int     fd;
    char    *str;

    if ((fd = open(av[1], O_RDONLY)) < 0)
    {
        perror("Error\nOpen");
        exit(-1);
    }  
    if (ac == 2)
    {
        parse_rt_file(fd);
        create_image();
    }
    if (ac == 3)
    {
        if (ft_strcmp(av[2], "--save") == 0)
        {
            /*save_as_bmp();*/
            return (0);
        }
        else
        
        
    }
    return (0);
}
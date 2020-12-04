/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:08:03 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/04 13:13:17 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

/*
Note: the functions in "string" library should be replaced by theire libft equivalent
*/

void    rt_print_error(const char* string)
{
    write(2, string, strlen(string));
    write(2, "\n", 1);
    exit(1);
}

int     open_rt_file(int ac, char *av[])
{
    int     fd;

    if (ac == 1)
        rt_print_error("Error\nminirt: no input file");
    if (ac > 3)
        rt_print_error("Error\nminirt: too many arguments");
    if ((fd = open(av[1], O_RDONLY)) < 0)
    {
        perror("Error\nOpen");
        exit(1);
    }
    if (strcmp(strchr(av[1], '.'), ".rt"))
        rt_print_error("Error\nminirt: wrong file format");
    if (ac == 3 && strcmp(av[2], "--save") != 0)
        rt_print_error("Error\nminirt: wrong argument\n");
    return (fd);
}
/*
** The main function should be something like this:
** ************************************************
**
**  int     main(int ac, char* av[])
**  {
**      int         fd;
**      t_scene     scene;
**      void        *img;
**  
**      fd = open_rt_file(ac, av);
**      scene = rt_parse(fd);
**      img = create_image(scene);
**      if (ac == 2)
**          display_image(img);
**      if (ac == 3)
**          save_image(img);
**      return (0);
**  }
** *************************************************
*/

int main(int ac, char* av[])
{
    int     fd;
//    char    *str;

    // if (ac == 1)
    // {
    //     write(2, "Error\nminirt: no input file\n", 29);
    //     exit(1);
    // }
    fd = open_rt_file(ac, av);
    printf("parsing\n");
    printf("creating image\n");
    if (ac == 2)
    {
        // if ((fd = open(av[1], O_RDONLY)) < 0)
        // {
        //     perror("Error\nOpen");
        //     exit(1);
        // }
        // if (strcmp(strchr(av[1], '.'), ".rt"))
        // {
        //     write(2, "Error\nminirt: wrong file format\n", 33);
        //     exit(1);
        // }
        printf("displaying image\n");
        // parse_rt_file(fd);
        // create_image();
    }
    if (ac == 3)
    {
        // if ((fd = open(av[1], O_RDONLY)) < 0)
        // {
        //     perror("Error\nOpen");
        //     exit(1);
        // }
        // if (strcmp(strchr(av[1], '.'), ".rt"))
        // {
        //     write(2, "Error\nminirt: wrong file format\n", 33);
        //     exit(1);
        // }
        // if (strcmp(av[2], "--save") == 0)
        // {
        //     printf("ac == %d\n", ac);
        //     // save_image_bmp();
        // }
        // else
        // {
        //     write(2, "Error\nminirt: wrong argument\n", 30);
        //     exit (1);
        // }
        printf("the image is saved and no display was generated\n");
    }
    // else
    // {
    //     write(2, "Error\nminirt: too many arguments\n", 34);
    //     exit (1);
    // }
    return (0);
}
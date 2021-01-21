/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:08:03 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/21 19:22:08 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

  int     main(int ac, char* av[])
  {
      int         fd;
      t_scene     scene;
      t_mlibx		mlibx;
  
      fd = open_rt_file(ac, av);
      rt_scene_initialize(&scene);
      rt_parse(fd, &scene);
      rt_image_create(&scene, &mlibx);
      if (ac == 2)
          display_rt_image(&scene, &mlibx);
    //   if (ac == 3)
    //       save_rt_image(&mlibx);
		rt_free_scene(&scene);
      return (0);
  }
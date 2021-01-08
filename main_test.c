/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:55:09 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/08 16:10:45 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vect(t_vect vect)
{
	printf("x == %f y == %f z == %f\n", vect.x , vect.y, vect.z);
}

void	print_elem_name(int elem)
{
	if (elem == rt_square)
		printf("square\n");
	else if (elem == rt_triangle)
		printf("rt_triangle\n");
	else if (elem == rt_sphere)
		printf("sphere\n");
	else if (elem == rt_cylinder)
		printf("cylinder\n");
	else if (elem == rt_plane)
		printf("plane\n"); 
}


void	print_sq(t_square *sq)
{
	printf("square origin == ");
	print_vect(sq->origin);
	printf("square normal == ");
	print_vect(sq->normal);
	printf("square side == %f\n", sq->side);
	printf("square color == %X\n", sq->color);
}

void	print_sphere(t_sphere *sp)
{
	printf("sphere origin == ");
	print_vect(sp->o);
	printf("sphere radius == %f\n", sp->r);
	printf("sphere color == %X\n", sp->color);
}

void	print_cylinder(t_cylinder *cy)
{
	printf("cylinder origin == ");
	print_vect(cy->origin);
	printf("cylinder axis == ");
	print_vect(cy->axis);
	printf("cylinder radius == %f\n", cy->radius);
	printf("cylinder height == %f\n", cy->height);
	printf("cylinder color == %X\n", cy->color);
}

void	print_triangle(t_triangle *tr)
{
	printf("triangle point a ");
	print_vect(tr->pt_a);
	printf("triangle point b ");
	print_vect(tr->pt_b);
	printf("triangle point c ");
	print_vect(tr->pt_c);
	printf("triangle color %X\n", tr->color);
}

void	print_plane(t_plane *pl)
{
	printf("plane position ");
	print_vect(pl->p);
	printf("plane normal ");
	print_vect(pl->n);
	printf("plane color %X\n", pl->color);
}

void	print_elem(int elem, void *content)
{
	if (elem == rt_square)
		return (print_sq((t_square *)content));
	else if (elem == rt_plane)
		return (print_plane((t_plane *)content));
	else if (elem == rt_triangle)
		return (print_triangle((t_triangle *)content));
	else if (elem == rt_sphere)
		return (print_sphere((t_sphere *)content));
	else if (elem == rt_cylinder)
		return (print_cylinder((t_cylinder *)content));
}

void	print_scene(t_scene *scene)
{
	t_cam	*cam;
	t_light	*light;
	int		count;
	t_list *lst;

	printf("ambiant color == %X\n", scene->amb->color);
	printf("ambiant intensity == %f\n", scene->amb->intensity);
	printf("resolution height == %d\n", scene->res->height);
	printf("resolution width == %d\n", scene->res->width);
	count = 0;
	lst = scene->cams;
	while (lst)
	{
		count++;
		cam = (t_cam *)(lst->content);
		printf("cam Number: %d\n", count);
		printf("cam position == ");
		print_vect(cam->c);
		printf("cam fov == %f\n", cam->fov);
		printf("cam direction == ");
		print_vect(cam->l);
		lst = lst->next;
	}
	count = 0;
	lst = scene->lights;
	while (lst)
	{
		count++;
		light = (t_light *)(lst->content);
		printf("Light Number: %d\n", count);
		printf("Light position == ");
		print_vect(light->l);
		printf("Light color == %X\n", light->color);
		printf("Light intensity == %f\n", light->intensity);
		lst = lst->next;
	}
	count = 0;
	lst = scene->objs;
	while (lst)
	{
		count++;
		printf("object Number: %d\n", count);
		print_elem_name(lst->element);
		print_elem(lst->element, lst->content);
		lst = lst->next;
	}
}

int			main(int ac, char* av[])
{
	int		fd;
	t_scene	scene;

	fd = open_rt_file(ac, av);
	rt_scene_initialize(&scene);
	rt_parse(fd, &scene);
	print_scene(&scene);
	rt_free_scene(&scene);
	return (0);
}
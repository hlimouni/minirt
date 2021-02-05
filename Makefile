# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 21:52:28 by hlimouni          #+#    #+#              #
#    Updated: 2021/02/05 18:56:27 by hlimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
LINKFLAGS=-Lmlx -framework OpenGL -framework AppKit
NAME=miniRT
LIBFT=libft.a
LIBMLX=libmlx.dylib

SRC=cam_ray_build.c \
	main.c \
	objs_intersect.c \
	pixel_shade.c \
	ray_intersect.c \
	rt_img_create.c \
	save_rt_image.c \
	parser/add_elem_to_scene.c \
	parser/get_next_line.c \
	parser/is_str.c \
	parser/is_str_types.c \
	parser/is_str_float.c \
	parser/objs_push.c \
	parser/rt_elemlen.c \
	parser/rt_exit.c \
	parser/rt_parse.c \
	parser/str_tof_vec.c \
	parser/translation.c \
	parser/rotation.c \
	t_vect_math/itovect.c \
	t_vect_math/mat_vect_prod.c \
	t_vect_math/solve_rt_quadtratic.c \
	t_vect_math/vectoi.c \
	t_vect_math/vector_operations.c \
	t_vect_math/vector_operations2.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LINKFLAGS)  $^ -o $(NAME)

*.o : minirt.h parser/parser.h t_vect_math/t_vect_math.h

parser/*.o : parser/parser.h t_vect_math/t_vect_math.h

t_vect_math/*.o : t_vect_math/t_vect_math.h

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@

$(LIBFT) :
	make bonus -C libft
	cp libft/$(LIBFT) .

$(LIBMLX) :
	make -C mlx
	cp mlx/$(LIBMLX) .

clean :
	make clean -C mlx
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(LIBMLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all

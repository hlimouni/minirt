# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 21:52:28 by hlimouni          #+#    #+#              #
#    Updated: 2021/01/21 17:35:24 by hlimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
AR=ar
ARFLAGS=rcs
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a

HEADER=ft_printf.h

SRC=ft_putnchar.c \
	ft_printf_tokenizer.c \
	ft_putp_field.c \
	ft_putu_field.c \
	ft_putnbr_field.c \
	ft_puthex_field.c \
	ft_puts_field.c \
	ft_putc_field.c \
	ft_printf.c \

SRCLIBFT=./libft/ft_atoi.c \
         ./libft/ft_itoa.c \
	     ./libft/ft_bzero.c \
	     ./libft/ft_isalnum.c \
	     ./libft/ft_isalpha.c \
	     ./libft/ft_isascii.c \
	     ./libft/ft_isdigit.c \
	     ./libft/ft_isprint.c \
	     ./libft/ft_memccpy.c \
	     ./libft/ft_memchr.c \
	     ./libft/ft_memcmp.c \
	     ./libft/ft_memcpy.c \
	     ./libft/ft_memmove.c \
	     ./libft/ft_nbrlen.c \
	     ./libft/ft_hexlen.c \
	     ./libft/ft_memset.c \
	     ./libft/ft_putccount.c \
	     ./libft/ft_putdcount.c \
	     ./libft/ft_calloc.c \
	     ./libft/ft_putss.c \
	     ./libft/ft_putchar_fd.c \
	     ./libft/ft_putstr_fd.c \
	     ./libft/ft_putchar.c \
	     ./libft/ft_putendl_fd.c \
	     ./libft/ft_putnbr_fd.c \
	     ./libft/ft_putnbr_hex.c \
	     ./libft/ft_strchr.c \
	     ./libft/ft_strcmp.c \
	     ./libft/ft_strdup.c \
	     ./libft/ft_strjoin.c \
	     ./libft/ft_strlcat.c \
	     ./libft/ft_strlen.c \
	     ./libft/ft_strmapi.c \
	     ./libft/ft_strncmp.c \
	     ./libft/ft_strnstr.c \
	     ./libft/ft_strrchr.c \
	     ./libft/ft_split.c \
	     ./libft/ft_strnlen.c \
	     ./libft/ft_substr.c \
	     ./libft/ft_strtrim.c \
	     ./libft/ft_tolower.c \
	     ./libft/ft_toupper.c \
	     ./libft/ft_strlcpy.c \

OBJ=$(SRC:.c=.o)
OBJLIBFT=$(SRCLIBFT:.c=.o)

all: $(NAME)

$(NAME) : $(OBJLIBFT) $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJLIBFT)

$(OBJ) : %.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJLIBFT) : %.o : %.c
	make -C libft

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all


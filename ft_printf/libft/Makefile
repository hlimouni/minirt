# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 15:24:42 by hlimouni          #+#    #+#              #
#    Updated: 2019/12/30 12:57:35 by hlimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
AR=ar
ARFLAGS=rcs
CFLAGS=-Wall -Wextra -Werror 
NAME=libft.a

HEADER=libft.h

SRC=ft_atoi.c \
	ft_itoa.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_nbrlen.c \
	ft_hexlen.c \
	ft_memset.c \
	ft_putccount.c \
	ft_putdcount.c \
	ft_calloc.c \
	ft_putss.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr_hex.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_split.c \
	ft_strnlen.c \
	ft_substr.c\
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strlcpy.c \

SRCB=ft_lstadd_back_bonus.c\
	 ft_lstadd_front_bonus.c \
	 ft_lstclear_bonus.c \
	 ft_lstmap_bonus.c \
	 ft_lstdelone_bonus.c \
	 ft_lstlast_bonus.c \
	 ft_lstsize_bonus.c \
	 ft_lstnew_bonus.c \
	 ft_lstiter_bonus.c \

OBJ=$(SRC:.c=.o)

OBJB=$(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(OBJB) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJB) $(OBJ)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all


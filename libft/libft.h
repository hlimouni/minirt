/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:08:14 by hlimouni          #+#    #+#             */
/*   Updated: 2021/01/06 08:40:58 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define MAXINT 0x7fffffff
# define MININT 0x80000000

typedef struct		s_list
{
	int				element;
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_putdcount(int nbr);
int					ft_nbrlen(int nbr);
int					ft_hexlen(int nb);
int					ft_putccount(char c);
int					ft_putss(char *str);
void				ft_lstclear(t_list **lst, void (*del)(void*));
int					ft_getstr_sign(char *str, int *index);
void				ft_free_null(void **ptr);
int					ft_free_ret(void **ptr, int ret);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
char				*ft_strdup(const char *str);
int					ft_atoi(const char *str);
int					ft_strtoi(char *str, int *num);
char				*ft_skip_spaces(const char *str);
char				*ft_itoa(int n);
void				ft_putnbr_hex(int nbr);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);
void				free_2d_array(char ***arr);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_bzero(void *dest, size_t len);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_datacpy(void *to, const void *from, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int value, size_t len);
char				*ft_strchr(const char *str, int chr);
int					ft_strchar_count(char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_toupper(int c);
size_t				ft_strlen(const char *str);
int					ft_tolower(int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *str, int c);
size_t				ft_strnlen(const char *str, size_t maxlen);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

#endif

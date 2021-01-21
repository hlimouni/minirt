/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:09:40 by hlimouni          #+#    #+#             */
/*   Updated: 2019/12/29 14:16:32 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# define FORMAT "cspdiuxX0123456789.-*%"

enum	e_tokens{flag, width, precision, type};
int		ft_printf(const char *fmt, ...);
char	*ft_tokenizer(char *str, int *field, va_list ap);
int		ft_putnchar(char c, int n);
int		ft_putnbr_field(int nbr, int *field);
int		ft_puthex_field(int nbr, int *field);
int		ft_putu_field(unsigned int nbr, int *field);
int		ft_putc_field(char c, int *field);
int		ft_puts_field(char *str, int *field);
int		ft_putp_field(void *ptr, int *field);

#endif

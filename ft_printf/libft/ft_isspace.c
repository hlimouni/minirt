/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:42:12 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/21 18:55:13 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ascii values of the backs
** checks for white-space characters.  In the "C" and "POSIX" locales, these 
** are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
** horizontal tab ('\t'), and vertical tab ('\v'). there ascii ranges
** from 8 to 13.
*/

#include "libft.h"

int		ft_isspace(int c)
{
	return ((c == '\n' || c == '\t' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r'));
}
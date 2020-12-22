/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:42:12 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/22 16:25:54 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return ((c == '\n' || c == '\t' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r'));
}
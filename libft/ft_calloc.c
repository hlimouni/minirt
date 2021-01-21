/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:28:13 by hlimouni          #+#    #+#             */
/*   Updated: 2019/10/31 22:58:53 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	full_size;

	full_size = count * size;
	ptr = malloc(full_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, full_size);
	return (ptr);
}

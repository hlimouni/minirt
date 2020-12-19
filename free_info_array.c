/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:54:45 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/19 16:54:51 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_info_arr(int ***info)
{

	int             i;

	i = 0;
	while ((*info)[i])
	{
	        free((*info)[i]);
	        (*info)[i] = NULL;
	        i++;
	}
	free(*info);
	*info = NULL;
}
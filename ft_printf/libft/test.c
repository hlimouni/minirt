/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 08:49:40 by hlimouni          #+#    #+#             */
/*   Updated: 2020/12/25 09:52:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

enum {integer, string};

void	print_voidptr(void *content, int type)
{
	if (type == integer)
		printf("%d\n", *((int *)content));
	else if (type == string)
		printf("%s\n", *((char **)content));
}

int main(void)
{
	t_list *list;
	int		data = 3;
	t_list *node;
	char	*str;
	
	str = "test";
	list = ft_lstnew(&data);
	list->element = integer;
	node = ft_lstnew(&str);
	node->element = string;
	ft_lstadd_back(&list, node);
	print_voidptr(list->content, integer);
	print_voidptr(list->next->content, string);
	return (0);
}
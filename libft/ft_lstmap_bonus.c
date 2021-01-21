/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:46:53 by hlimouni          #+#    #+#             */
/*   Updated: 2019/11/20 18:27:34 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clearnodes(t_list **alst, void (*del)(void *))
{
	ft_lstclear(alst, del);
	*alst = NULL;
	return (*alst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**tracer;
	t_list	*new;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	tracer = &lst;
	if (!(new = ft_lstnew(f((lst)->content))))
		return (ft_clearnodes(&new, del));
	ret = new;
	while (*tracer)
	{
		tracer = &(*tracer)->next;
		if (!(*tracer))
			new->next = NULL;
		else if (!(new->next = ft_lstnew(f(((*tracer)->content)))))
			return (ft_clearnodes(&ret, del));
		else
			new = new->next;
	}
	return (ret);
}

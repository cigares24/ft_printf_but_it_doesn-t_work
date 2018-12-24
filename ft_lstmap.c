/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:01:12 by asicat            #+#    #+#             */
/*   Updated: 2018/11/19 11:38:56 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*begin;

	tmp = (*f)(lst);
	if (!(res = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = res;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(res->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (begin);
}

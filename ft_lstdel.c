/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:46:41 by asicat            #+#    #+#             */
/*   Updated: 2018/11/19 10:43:47 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;
	t_list	*next;

	lst = *alst;
	while (lst)
	{
		next = lst->next;
		(*del)(lst->content, lst->content_size);
		free(lst);
		lst = next;
	}
	*alst = NULL;
}

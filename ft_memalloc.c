/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:11:42 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 12:15:11 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	n;

	n = 0;
	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	while (n < size)
	{
		ptr[n] = 0;
		n++;
	}
	return (ptr);
}

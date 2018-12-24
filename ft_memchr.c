/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:15:46 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 13:52:08 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (void*)s;
	while (i < n)
	{
		if (cpy[i] == (char)c)
			return (cpy + i);
		i++;
	}
	return (NULL);
}

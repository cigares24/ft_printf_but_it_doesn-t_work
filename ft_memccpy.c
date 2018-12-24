/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:55:37 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 13:51:23 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (void*)dst;
	source = (void*)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

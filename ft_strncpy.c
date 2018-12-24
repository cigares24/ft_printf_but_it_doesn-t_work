/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:03:20 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 13:45:57 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	n;

	n = 0;
	while (src[n] != '\0' && n < len)
	{
		dst[n] = src[n];
		n++;
	}
	while (n < len)
	{
		dst[n] = '\0';
		n++;
	}
	return (dst);
}

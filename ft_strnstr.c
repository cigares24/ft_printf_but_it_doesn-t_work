/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:34:17 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 13:57:25 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;
	int				i;

	n = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[n] != '\0' && n < len)
	{
		if (haystack[n] == needle[0])
		{
			i = 0;
			while (haystack[n + i] == needle[i] && needle[i] != '\0'
					&& (n + i) <= len)
				i++;
			if (needle[i] == '\0')
				return ((char*)(haystack + n));
		}
		n++;
	}
	return (NULL);
}

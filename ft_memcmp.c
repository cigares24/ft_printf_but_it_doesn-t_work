/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:59:48 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 17:06:36 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s_1;
	const unsigned char		*s_2;

	if (s1 == s2 || n == 0)
		return (0);
	s_1 = (const unsigned char*)s1;
	s_2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*s_1 != *s_2)
			return ((unsigned char)*s_1 - (unsigned char)*s_2);
		if (n)
		{
			s_1++;
			s_2++;
		}
	}
	return (0);
}

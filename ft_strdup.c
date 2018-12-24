/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:45:28 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 13:44:43 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		n;
	char	*copy;

	if (!(copy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		copy[n] = s[n];
		n++;
	}
	copy[n] = '\0';
	return (copy);
}

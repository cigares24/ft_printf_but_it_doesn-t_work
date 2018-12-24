/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:10:56 by asicat            #+#    #+#             */
/*   Updated: 2018/11/19 12:49:03 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] >= 'a' && str[n] <= 'z')
		{
			if (str[n - 1] < '0' || str[n - 1] > '9')
			{
				if (str[n - 1] < 'a' || str[n - 1] > 'z')
					str[n] = str[n] - 32;
			}
		}
		if (str[n] >= 'A' && str[n] <= 'Z')
		{
			if (str[n - 1] >= 'a' && str[n - 1] <= 'z')
				str[n] = str[n] + 32;
			if (str[n - 1] >= 'A' && str[n - 1] <= 'Z')
				str[n] = str[n] + 32;
		}
		n++;
	}
	return (str);
}

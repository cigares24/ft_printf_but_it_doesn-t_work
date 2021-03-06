/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:52:35 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 11:03:51 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		n;

	if (s == NULL)
		return ;
	n = 0;
	while (s[n] != '\0')
	{
		ft_putchar(s[n]);
		n++;
	}
}

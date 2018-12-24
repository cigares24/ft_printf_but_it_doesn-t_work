/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:18:13 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 15:39:40 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malloc_size(int nb)
{
	int	n;
	int	res;

	n = nb;
	res = 0;
	if (n == 0)
		return (2);
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res + 1);
}

static char	*strrev(char *str)
{
	int		n;
	int		i;
	char	tmp;

	n = 0;
	i = ft_strlen(str) - 1;
	while (n < i)
	{
		tmp = str[n];
		str[n] = str[i];
		str[i] = tmp;
		n++;
		i--;
	}
	return (str);
}

char		*ft_itoa(int nb)
{
	int		n;
	char	*str;

	n = 0;
	if (!(str = (char*)malloc(sizeof(char) * malloc_size(nb))))
		return (NULL);
	str[malloc_size(nb) - 1] = '\0';
	if (nb == -2147483648 && (nb = 214748364))
	{
		str[10] = '-';
		str[0] = '8';
		n++;
	}
	if (nb < 0 && (nb = -nb))
		str[malloc_size(nb) - 1] = '-';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[n++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str = strrev(str);
	return (str);
}

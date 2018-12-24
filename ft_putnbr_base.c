/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:49:41 by asicat            #+#    #+#             */
/*   Updated: 2018/11/19 12:50:10 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_check(char *base, int len)
{
	int n;
	int i;

	n = 0;
	if (len == 0 || len == 1)
		return (0);
	while (n <= len)
	{
		i = 0;
		while (i <= len)
		{
			if (base[n] == base[i] && n != i)
				return (0);
			if (base[i] == '-' || base[i] == '+')
				return (0);
			i++;
		}
		n++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;
	int		verif;

	n = (long)nbr;
	len = 0;
	while (base[len] != '\0')
		len++;
	verif = ft_putnbr_check(base, len);
	if (verif == 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
		ft_putchar(base[n % len]);
	}
	else
		ft_putchar(base[n % len]);
}

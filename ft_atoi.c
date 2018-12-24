/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:32:18 by asicat            #+#    #+#             */
/*   Updated: 2018/11/15 17:53:29 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	atoi_process(const char *str, int sign, int n)
{
	long	res;

	res = 0;
	while (str[n])
	{
		if (res >= 922337203685477580 && sign == 1 && str[n] > 7 + 48)
			return (-1);
		if (res >= 922337203685477580 && sign == -1 && str[n] > 8 + 48)
			return (0);
		if (48 <= str[n] && str[n] <= 57)
			res = res * 10 + (str[n++] - 48);
		else
			return (res * sign);
	}
	return (res * sign);
}

int				ft_atoi(const char *str)
{
	int		sign;
	int		n;

	n = 0;
	sign = 1;
	while (str[n] == '\t' || str[n] == '\v' || str[n] == '\r' ||
			str[n] == '\n' || str[n] == '\f' || str[n] == ' ')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n++] == '-')
			sign = -1;
	}
	return (atoi_process(str, sign, n));
}

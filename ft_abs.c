/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:54:17 by asicat            #+#    #+#             */
/*   Updated: 2018/12/17 10:54:58 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:28:38 by asicat            #+#    #+#             */
/*   Updated: 2018/07/16 16:03:24 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int index;

	index = 0;
	if (str[0] == '\0')
		return (1);
	while (str[index])
	{
		if ((str[index] >= 65 && str[index] <= 90)
			|| (str[index] >= 97 && str[index] <= 122))
			index++;
		else
			return (0);
	}
	return (1);
}

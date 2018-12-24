/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:41:37 by asicat            #+#    #+#             */
/*   Updated: 2018/11/19 12:47:09 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s)
{
	int		n;

	n = 0;
	while (s[n] == '\t' || s[n] == '\n' || s[n] == ' ')
		n++;
	return (n);
}

static int	find_end(char const *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	size_t	n;
	size_t	i;
	char	*str;
	int		k;

	if (s == NULL)
		return (NULL);
	n = find_start(s);
	k = 0;
	if (n == ft_strlen(s))
	{
		if (!(str = (char*)malloc(1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = find_end(s);
	if (!(str = (char*)malloc(sizeof(char) * (i - n + 2))))
		return (NULL);
	while (n <= i)
		str[k++] = s[n++];
	str[k] = '\0';
	return (str);
}

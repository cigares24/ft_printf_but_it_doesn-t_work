/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:56:19 by asicat            #+#    #+#             */
/*   Updated: 2018/11/16 15:59:55 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_wd(const char *s, char c)
{
	int		i;
	int		in_substring;

	in_substring = 0;
	i = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	word_len(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**words;
	char	*word;
	int		words_total;
	int		words_actual;
	int		i;

	if (!s || !c || !(words = (char**)malloc(sizeof(*words) * nb_wd(s, c) + 1)))
		return (NULL);
	words_total = nb_wd(s, c);
	words_actual = 0;
	while (words_actual < words_total)
	{
		i = 0;
		if (!(word = (char*)malloc(sizeof(char) * word_len((char*)s, c) + 1)))
			return (NULL);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			word[i++] = *s++;
		word[i] = '\0';
		words[words_actual++] = word;
	}
	words[words_actual] = NULL;
	return (words);
}

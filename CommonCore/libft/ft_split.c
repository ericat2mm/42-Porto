/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:04:07 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/24 17:00:49 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
			words++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (words);
}

static void	ft_freemalloc(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_tudo(char const *s, char **tab, char c, size_t j)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			tab[k] = malloc(sizeof(char) * (i - j + 1));
			if (!tab[k])
			{
				ft_freemalloc(tab);
				return (NULL);
			}
			ft_strlcpy(tab[k++], &s[j], i - j + 1);
		}
	}
	tab[k] = NULL;
	return ((char **)tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_tudo(s, tab, c, j);
	return (tab);
}

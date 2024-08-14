/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:01:10 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 11:01:57 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int dimensions(int *x, int *y, char *file)
{
    int     fd;
    char    *line;
    char    **split_line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
    while ((line = get_next_line(fd)) != NULL)
    {
        (*y)++;
        if (*y == 1)
        {
            split_line = ft_split(line, ' ');
            *x = count_words(line, ' ');
            free(split_line);
        }
        free(line);
    }
    close(fd);
    return (0);
}

int count_words(char *s, char c)
{
    int i;
    int words;

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
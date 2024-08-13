/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:51:00 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 18:15:40 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int dimensions(int *x, int *y, char *file)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
    while (get_next_line(fd))
    {
        (*y)++;
        if (*y == 1)
        {
            line = ft_strdup(line);
            *x = count_words(line, ' ');
            free(line);
        }
    }
    close(fd);
    return (0);
}

int count_words(char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
        if (s[i])
            i++;
    }
    return (count);
}
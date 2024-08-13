/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:51 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 14:31:04 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_dimensions(int *x, int *y, char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);
    while (get_next_line(fd))
    {
        (*y)++;
        if (*y == 1)
        {
            line = ft_strdup(line);
            *x = ft_count_words(line, ' ');
            free(line);
        }
    }
    close(fd);
    return (0);
}
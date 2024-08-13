/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 23:50:41 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    *read_map(char *file, t_map *map)
{
    int     fd;
    char    *line;
    int     y;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    y = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        map->matrix[y] = (t_point *)malloc(sizeof(t_point) * map->width);
        if (!map->matrix[y])
            return (NULL);
        matrix(map->matrix[y], line, y);
        free(line);
        y++;
        line = get_next_line(fd);
    }
    close(fd);
    return (line); 
}

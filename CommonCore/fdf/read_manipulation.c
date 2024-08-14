/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 13:51:11 by emedeiro         ###   ########.fr       */
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
    while ((line = get_next_line(fd)) != NULL)
    {
        map->matrix[y] = (t_point *)malloc(sizeof(t_point) * map->width);
        if (!map->matrix[y])
            return (NULL);
        matrix(map->matrix[y], line, y);
        free(line);
        y++;
    }
    close(fd);
    return ("SUCCESS"); 
}

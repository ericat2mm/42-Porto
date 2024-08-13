/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 20:38:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    *read_map(char *file, t_map *map)
{
    int     fd;
    char    *line;
    char    **split_line;
    int     i;
    int     j;
    t_point new_point;

    line = NULL;
    fd = open(file, O_RDONLY);
    map->matrix = (t_point **)malloc(sizeof(int *) * map->height);
    i = 0;
    while (get_next_line(fd) != NULL)
    {
        map->matrix[i] = (t_point *)malloc(sizeof(int) * map->width);
        split_line = ft_split(line, ' ');
        j = 0;
        while (j < map->width)
        {
            new_point.value = ft_atoi(split_line[j]);
            map->matrix[i][j] = new_point;
            j++;
        }
        i++;
    }
    return (line);
}
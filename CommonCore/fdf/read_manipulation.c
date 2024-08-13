/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:26:31 by emedeiro         ###   ########.fr       */
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

    line = NULL;
    fd = open(file, O_RDONLY);
    map->matrix = (int **)malloc(sizeof(int *) * map->height);
    i = 0;
    while (get_next_line(fd) > 0)
    {
        map->matrix[i] = (int *)malloc(sizeof(int) * map->width);
        split_line = ft_split(line, ' ');
        j = 0;
        while (j < map->width)
        {
            map->matrix[i][j] = ft_atoi(split_line[j]);
            j++;
        }
        i++;
    }
    return (line);
}   
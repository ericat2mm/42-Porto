/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:20:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 18:56:02 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map   *ft_data(char *file)
{
    t_map   *map;
    char    *line;
    int     fd;
	int		x;
	int		y;

    dimensions(&x, &y, file);
    if (!(map = malloc(sizeof(t_map))) 
		|| !(map->matrix = malloc(y * sizeof(t_point *))))
        return (NULL);
    map->height = y;
    map->width = x;
    if ((fd = open(file, O_RDONLY)) < 0)
        return (NULL);
    y = 0;
    while ((line = get_next_line(fd)))
    {
        if (!(map->matrix[y] = malloc(x * sizeof(t_point))))
            return (NULL);
        matrix(map->matrix[y], line, y); 
        free(line);
        y++;
    }
    close(fd);
    return (map);
}


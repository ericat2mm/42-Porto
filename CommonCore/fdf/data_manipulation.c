/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:20:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 23:31:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map   *ft_data(char *file)
{
    t_map   *map;
    int     x = 0;
    int     y = 0;

    if (dimensions(&x, &y, file) == -1)
        return (NULL);
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = x;
    map->height = y;
    map->matrix = (t_point **)malloc(sizeof(t_point *) * y);
    if (!map->matrix || !read_map(file, map))
        return (NULL);
    return (map);
}



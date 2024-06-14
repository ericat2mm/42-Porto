/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:40:31 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 16:56:58 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *create_map()
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->point = NULL;
    return (map);
}

void draw_map(t_map *map)
{
    t_point *point;

    for (point = map->point; point; point = point->next)
    {
        ft_putnbr_fd(point->x, 1);
        ft_putchar_fd(' ', 1);
        ft_putnbr_fd(point->y, 1);
        ft_putchar_fd(' ', 1);
        ft_putnbr_fd(point->z, 1);
        ft_putchar_fd('\n', 1);
    }
}

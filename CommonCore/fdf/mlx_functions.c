/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:15:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 17:19:28 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:21:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 00:41:27 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
    int dx = ft_abs(p2.x - p1.x);
    int dy = ft_abs(p2.y - p1.y);
    int sx = p1.x < p2.x ? 1 : -1;
    int sy = p1.y < p2.y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.y, p1.color);
        if (p1.x == p2.x && p1.y == p2.y)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            p1.x += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            p1.y += sy;
        }
    }
}

void draw_map(t_map *map)
{
    void *mlx_ptr;
    void *win_ptr;
    t_point *point;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FdF");

    point = map->point;
    while (point && point->next)
    {
        draw_line(*point, *(point->next), mlx_ptr, win_ptr);
        point = point->next;
    }

    mlx_loop(mlx_ptr);
}

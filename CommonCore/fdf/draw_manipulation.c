/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:32:39 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 18:14:47 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw(t_fdf *win)
{
    int x;
    int y;

    y = 0;
    while (y < win->map->height)
    {
        x = 0;
        while (x < win->map->width)
        {
            if (x < win->map->width - 1)
                bresenham_algorithm(&(win->map->matrix[y][x]), &(win->map->matrix[y][x + 1]), win);
            if (y < win->map->height - 1)
                bresenham_algorithm(&(win->map->matrix[y][x]), &(win->map->matrix[y + 1][x]), win);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
    screen_settings(win);
    return (0);
}

void bresenham_algorithm(t_point *point_1, t_point *point_2, t_fdf *win)
{
    float x;
    float y;
    int max;
    float dx;
    float dy;
    int Pa;
    int Pb;

    max = 0;
    apply_isometric(point_1, point_2, win);
    dx = step_one(point_1, point_2);
    dy = step_one_two(point_1, point_2);
    max = step_two(dx, dy, max);
    Pa = step_two_two(dx, max);
    Pb = step_two_three(dy, max);
    x = point_1->x;
    y = point_1->y;
    while ((int)(x - point_2->x) || (int)(y - point_2->y))
    {
        mlx_pixel_put(&win->img, win->img.img, x, y, 0xFFFFFF);
        x += Pa;
        y += Pb;
    }
}

void apply_isometric(t_point *point_1, t_point *point_2, t_fdf *win)
{
    if (win->view != 3)
    {
        // Aplicando a transformação isométrica
        isometric(point_1->x, point_1->y, win->map->matrix[(int)(point_1->y)][(int)(point_1->x)].z);
        isometric(point_2->x, point_2->y, win->map->matrix[(int)(point_2->y)][(int)(point_2->x)].z);
    }
}


void isometric(float *x, float *y, float z)
{
    float previous_x;
    float previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}
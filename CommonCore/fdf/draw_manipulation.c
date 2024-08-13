/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:32:39 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 16:16:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw(t_fdf *win)
{
    int x;
    int y;

    background(win, 0x000000);
    y = 0;
    while (y < win->map->height)
    {
        x = 0;
        while (x < win->map->width)
        {
            if (x < win->map->width - 1)
                bresenham_algorithm(x, y, x + 1, y, win);
            if (y < win->map->height - 1)
                bresenham_algorithm(x, y, x, y + 1, win);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
    return (0);
}

void   bresenham_algorithm(int x_a, int y_a, int x_b, int y_b, t_fdf *win)
{
    float x;
    float y;
    int max;
    float dx;
    float dy;
    int Pa;
    int Pb;
    
    if (win->view != 3)
    {
        isometric(&x_a, &y_a, win->map->matrix[y_a][x_a], win);
        isometric(&x_b, &y_b, win->map->matrix[y_b][x_b], win);
    }
    step_one(&x_a, &y_a, &x_b, &y_b);
    step_two(&x_a, &y_a, &x_b, &y_b, &dx, &dy, &max);
    while ((int)(x - x_b) || (int)(y - y_b))
    {
        mlx_pixel_put(win->mlx, win->win, x, y, 0xFFFFFF);
        x += Pa;
        y += Pb;
    }
}
void isometric(int x, int y, int z, t_fdf *win)
{
    int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    x = (previous_x - previous_y) * cos(0.523599);
    y = -z + (previous_x + previous_y) * sin(0.523599);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:32:39 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 20:29:54 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw(t_fdf *win)
{
    int x;
    int y;

    background(win->img, 0x000000);
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
void bresenham_algorithm(float x_a, float y_a, float x_b, float y_b, t_fdf *win)
{
    float x;
    float y;
    int max;
    float dx;
    float dy;
    int Pa;
    int Pb;

    max = 0;
    apply_isometric(win, &x_a, &y_a, &x_b, &y_b);
    dx = step_one(&x_a, &x_b);
    dy = step_one_two(&y_a, &y_b);
    max = step_two(dx, dy, max);
    Pa = step_two_two(dx, max);
    Pb = step_two_three(dy, max);
    x = x_a;
    y = y_a;
    while ((int)(x - x_b) || (int)(y - y_b))
    {
        mlx_pixel_put(win->mlx, win->win, (int)x, (int)y, 0xFFFFFF);
        x += Pa;
        y += Pb;
    }
}

void apply_isometric(t_fdf *win, float *x_a, float *y_a, float *x_b, float *y_b)
{
    if (win->view != 3)
    {
        // Aplicando a transformação isométrica
        isometric(x_a, y_a, win->map->matrix[(int)*y_a][(int)*x_a].z);
        isometric(x_b, y_b, win->map->matrix[(int)*y_b][(int)*x_a].z);
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
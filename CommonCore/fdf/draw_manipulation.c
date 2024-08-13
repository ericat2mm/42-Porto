/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:42:27 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:09:13 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(int x_a, int y_a, int x_b, int y_b, t_fdf *fdf)
{
    int delta_a;
    int delta_b;
    int delta_x;
    int delta_y;

    delta_a = y_a - x_a;
    delta_b = y_b - x_b;
    delta_x = x_b - x_a;
    delta_y = y_b - y_a;
    
    if (abs(delta_a) > abs(delta_b))
    {
        if (delta_a < 0)
            draw_line_low(x_b, y_b, x_a, fdf, delta_x, delta_y);
        else
            draw_line_low(x_a, y_a, x_b, fdf, delta_x, delta_y);
    }
    else
    {
        if (delta_b < 0)
            draw_line_high(x_b, y_b, y_a, fdf, delta_x, delta_y);
        else
            draw_line_high(x_a, y_a, y_b, fdf, delta_x, delta_y);
    }
}

void draw_line_low(int x_a, int y_a, int x_b, t_fdf *fdf, int delta_x, int delta_y)
{
    int xi;
    int d;
    int y;
    
    xi = 1;
    if (delta_y < 0)
    {
        xi = -1;
        delta_y = -delta_y;
    }
    d = (2 * delta_y) - delta_x;
    y = y_a;
    while (x_a <= x_b)
    {
        mlx_pixel_put(fdf->mlx, fdf->win, x_a, y, 0xFFFFFF);
        if (d > 0)
        {
            y = y + xi;
            d = d + (2 * (delta_y - delta_x));
        }
        else
            d = d + 2 * delta_y;
        x_a++;
    }
}

void draw_line_high(int x_a, int y_a, int y_b, t_fdf *fdf, int delta_x, int delta_y)
{
    int xi;
    int d;
    int x;
    
    xi = 1;
    if (delta_x < 0)
    {
        xi = -1;
        delta_x = -delta_x;
    }
    d = (2 * delta_x) - delta_y;
    x = x_a;
    while (y_a <= y_b)
    {
        mlx_pixel_put(fdf->mlx, fdf->win, x, y_a, 0xFFFFFF);
        if (d > 0)
        {
            x = x + xi;
            d = d + (2 * (delta_x - delta_y));
        }
        else
            d = d + 2 * delta_x;
        y_a++;
    }
}


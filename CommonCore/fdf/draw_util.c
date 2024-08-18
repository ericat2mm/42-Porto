/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:10:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/18 12:14:50 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_color(t_fdf *data, t_point p0, t_point p1)
{
    int color;

    if (data->color)
    {
        if (p0.color == p1.color)
            color = p0.color;
        else
            color = 0xFFFFFF;
    }
    else
        color = 0xFFFFFF;
    return (color);
}

int coordinate_x(float x, t_fdf *data)
{
    return (x * data->scale + data->shift_x);
}

int coordinate_y(float y, t_fdf *data)
{
    return (y * data->scale + data->shift_y);
}

void set_coordinates(t_point *p0, t_point *p1, t_fdf *data)
{
    zoom(p0, p1, data);
    if (data->is_isometric)
    {
        isometric(p0, data->angle);
        isometric(p1, data->angle);
    }
    p0->x += data->shift_x;
    p0->y += data->shift_y;
    p1->x += data->shift_x;
    p1->y += data->shift_y;
}
void isometric(t_point *p, float angle)
{
    p->x = (p->x - p->y) * cos(angle);
    p->y = (p->x + p->y) * sin(angle) - p->z;
}
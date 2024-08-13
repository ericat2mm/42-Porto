/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 14:37:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    render(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while (y < fdf->map->height)
    {
        x = 0;
        while (x < fdf->map->width)
        {
            if (x < fdf->map->width - 1)
                draw_line(x, y, x + 1, y, fdf);
            if (y < fdf->map->height - 1)
                draw_line(x, y, x, y + 1, fdf);
            x++;
        }
        y++;
    }
}
void    background(t_image *img, int color)
{
    int i;

    i = 0;
    while (i < WIN_WIDTH * WIN_HEIGHT)
    {
        ((int *)img->data)[i] = color;
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:25:20 by emedeiro         ###   ########.fr       */
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
                draw_line(fdf->map->matrix[y][x],fdf->map->matrix[y][x], fdf->map->matrix[y][x + 1], fdf->map->matrix[y][x + 1], fdf);
            if (y < fdf->map->height - 1)
                draw_line(fdf->map->matrix[y][x],fdf->map->matrix[y][x], fdf->map->matrix[y + 1][x], fdf->map->matrix[y + 1][x], fdf);
            x++;
        }
        y++;
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 18:37:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    render(t_fdf *fdf)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->map->height)
    {
        j = 0;
        while (j < fdf->map->width)
        {
            if (j < fdf->map->width - 1)
                draw(fdf->win);
            if (i < fdf->map->height - 1)
                draw(fdf->win);
            j++;
        }
        i++;
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


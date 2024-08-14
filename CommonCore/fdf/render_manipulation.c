/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 08:02:13 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void render(t_fdf *fdf)
{
    fdf->mlx = mlx_init();
    if (!fdf->mlx)
    {
        free_fdf(fdf);
        exit(EXIT_FAILURE);
    }
    fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
    if (!fdf->win)
    {
        free_fdf(fdf);
        exit(EXIT_FAILURE);
    }
    fdf->img = (t_image *)malloc(sizeof(t_image));
    if (!fdf->img)
    {
        free_fdf(fdf);
        exit(EXIT_FAILURE);
    }
    fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, 
        &fdf->img->size_l, &fdf->img->endian);
    mlx_loop_hook(fdf->mlx, draw, fdf);
    mlx_key_hook(fdf->win, key_hook, fdf);
    mlx_hook(fdf->win, 17, 0, exit_hook, fdf);
    mlx_loop(fdf->mlx);
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

// void render(t_fdf *fdf)
// {
//     fdf->mlx = mlx_init();
//     if (!fdf->mlx)
//         exit_free(fdf);
//     fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
//     if (!fdf->win)
//         exit_free(fdf);
//     fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
//     fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
//     mlx_loop_hook(fdf->mlx, draw, fdf);
//     mlx_key_hook(fdf->win, key_hook, fdf);
//     mlx_hook(fdf->win, 17, 0, exit_hook, fdf);
//     mlx_loop(fdf->mlx);
// }



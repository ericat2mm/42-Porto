/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 00:11:57 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void render(t_fdf *fdf)
// {
//     fdf->mlx = mlx_init();
//     if (!fdf->mlx)
//     {
//         free_fdf(fdf);
//         exit(EXIT_FAILURE);
//     }
//     fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
//     if (!fdf->win)
//     {
//         free_fdf(fdf);
//         exit(EXIT_FAILURE);
//     }
//     fdf->img = (t_image *)malloc(sizeof(t_image));
//     if (!fdf->img)
//     {
//         free_fdf(fdf);
//         exit(EXIT_FAILURE);
//     }
//     fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
//     fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, 
//         &fdf->img->size_l, &fdf->img->endian);
//     mlx_loop_hook(fdf->mlx, draw, fdf);
//     mlx_key_hook(fdf->win, mouse_hook, fdf);
//     mlx_hook(fdf->win, 17, 0, key_hook, fdf);
//     mlx_loop(fdf->mlx);
// }
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

void	render(t_map *map)
{
	t_mlx	*win;

	win = malloc(sizeof(t_mlx)); 
	set_up_win(win);
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIN_WIDTH, WIN_HEIGHT, "Fdf");
	win->map = map; 
	win->img.img = mlx_new_image(win->mlx_connect, WIN_WIDTH, WIN_HEIGHT);
	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, key_hook, win); 
	mlx_hook(win->mlx_win, 4, 0, mouse_hook, win);
	mlx_hook(win->mlx_win, 17, 0, key_hook, win);
	mlx_loop(win->mlx_connect); 
}
void   set_up_win(t_mlx *win)
{
    win->win = malloc(sizeof(t_fdf));
    win->win->view = 1;
    win->win->map = init_map();
    win->win->map->zoom = 20;
    win->win->map->width = 0; 
    win->win->map->height = 0;
}
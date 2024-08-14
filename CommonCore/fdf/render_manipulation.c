/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:01:25 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 17:09:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    background(t_image *img, int color)
{
	int	i;
    int	j;

    i = 0;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
        {
            img_pix_put(img, j, i, color);
            j++;
        }
        ++i;
    }
    printf("DESENHEI");
}
void	img_pix_put(t_image *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->size_l + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void render(t_fdf *fdf)
{
    fdf->img.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, &fdf->img.size_l, &fdf->img.endian);
    background(&fdf->img, 0x000000); // Pinta o fundo de preto
    if (draw(fdf) == -1)
    {
        free_fdf(fdf);
        return;
    }
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
    //mlx_key_hook(fdf->win, key_hook, fdf); // Configure os eventos de teclado, se necessário
    mlx_hook(fdf->win, 17, 0, exit_hook, fdf); // Hook para fechar a janela
    mlx_loop(fdf->mlx);
}



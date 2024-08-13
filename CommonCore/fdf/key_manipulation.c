/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:03:41 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:10:53 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//função que fecha a janela ao apertar a tecla esc
int key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == 53)
    {
        free_map(fdf->map);
        free_fdf(fdf);
        exit(0);
    }
    return (0);
}
//função que aumenta ou diminui o zoom ao rolar o mouse
int mouse_hook(int button, t_fdf *fdf)
{
    if (button == 4)
    {
        fdf->map->zoom += 1;
        render(fdf);
    }
    else if (button == 5)
    {
        fdf->map->zoom -= 1;
        render(fdf);
    }
    return (0);
}


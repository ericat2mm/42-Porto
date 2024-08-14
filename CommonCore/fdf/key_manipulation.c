/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:03:41 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 07:58:26 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     exit_hook(t_fdf *fdf)
{
    free_fdf(fdf);
    exit(EXIT_SUCCESS);
    return (0);
}
int key_hook(int button, t_fdf *fdf)
{
    if (button == 126) // tecla para cima
        fdf->map->y_offset -= 10;
    if (button == 125) // tecla para baixo
        fdf->map->y_offset += 10;
    if (button == 123) // tecla para esquerda
        fdf->map->x_offset -= 10;
    if (button == 124) // tecla para direita
        fdf->map->x_offset += 10;
    if (button == 69) // tecla +
        fdf->map->zoom += 1;
    if (button == 78) // tecla -
        fdf->map->zoom -= 1;
    if (button == 116) // tecla page up que é o botão 5 do numpad
        fdf->map->z_divisor += 1;
    if (button == 121) // tecla page down que é o botão 3 do numpad
        fdf->map->z_divisor -= 1;
    if (button == 13) // tecla W
        fdf->map->alpha += 0.05;
    if (button == 1) // tecla S
        fdf->map->alpha -= 0.05;
    if (button == 0) // tecla A
        fdf->map->beta -= 0.05;
    if (button == 2) // tecla D
        fdf->map->beta += 0.05;
    return (0);
}


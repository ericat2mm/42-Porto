/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:03:41 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 00:10:40 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
int mouse_hook(int button, t_fdf *fdf)
{
    t_map *map;
    
    map = fdf->map;
    if (button == 'w') //scroll up
        fdf->map->zoom += 1;
    else if (button == 's') //scroll down
        fdf->map->zoom -= 1;
    else if (button == 'a') //scroll left
        fdf->map->zoom += 1;
    else if (button == 'd') //scroll right
        fdf->map->zoom -= 1;
    render(map);
    return (0);
}


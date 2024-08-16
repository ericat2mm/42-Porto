/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:02:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/15 14:30:57 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *init_map(void)
{
    t_map *map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->matrix = NULL;
    map->width = 0;
    map->height = 0;
    return (map);
}

t_fdf *init_fdf(t_map *map)
{
    t_fdf *fdf;
    
    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    if (!fdf)
        return (NULL);
    fdf->mlx = mlx_init();
    fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
    fdf->map = map;
    return (fdf);
}
void    set_window(t_fdf *fdf)
{
    fdf->mlx_connect = 0;
    fdf->mlx_win = 0;
	fdf->map = 0;
    fdf->map->x_offset = 900;
    fdf->map->y_offset = 900;
	fdf->view = 0.78;
}
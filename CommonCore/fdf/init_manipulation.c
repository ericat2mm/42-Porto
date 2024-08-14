/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:02:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 16:38:30 by emedeiro         ###   ########.fr       */
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

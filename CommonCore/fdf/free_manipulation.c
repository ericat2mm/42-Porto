/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:02:18 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 23:02:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_map(t_map *map)
{
    int i = 0;

    while (i < map->height)
    {
        free(map->matrix[i]);
        i++;
    }
    free(map->matrix);
    free(map);
}

void free_fdf(t_fdf *fdf)
{
    free_map(fdf->map);
    free(fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:52:54 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 11:03:08 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->matrix[i]);
        i++;
    }
    free(map->matrix);
    free(map);
}
void   free_fdf(t_fdf *fdf)
{
    free(fdf->map);
    free(fdf);
}

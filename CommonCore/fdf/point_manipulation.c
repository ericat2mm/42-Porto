/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:14:26 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 18:47:16 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    point(t_point *point, char *coords, int x, int y)
{
    char    **data;

    data = ft_split(coords, ',');
    if (!data)
        return ;
    point->z = ft_atoi(data[0]);
    point->x = x;
    point->y = y;
    // Liberando memória usada pelo ft_split
    int i;
    i = 0;
    while (data[i])
        free(data[i++]);
    free(data);
}

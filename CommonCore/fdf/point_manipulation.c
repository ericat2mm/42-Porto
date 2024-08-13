/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:14:26 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 23:32:27 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    point(t_point *point, char *coords, int x, int y)
{
    char    **data;
    int     i;
    
    data = ft_split(coords, ',');
    if (!data)
        return ;
    point->z = ft_atoi(data[0]);
    point->x = x;
    point->y = y;
    i = 0;
    while (data[i] != NULL)
    {
        free(data[i]);
        i++;
    }
    free(data);
}

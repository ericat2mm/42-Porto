/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:03:39 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 20:21:28 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    matrix(t_point *row, char *line, int y)
{
    char    **data;
    int     x;

    x = 0;
    data = ft_split(line, ' ');
    if (!data)
        return ;
    while (data[x])
    {
        point(&row[x], data[x], x, y); 
        x++;
    }
    free(data);
}

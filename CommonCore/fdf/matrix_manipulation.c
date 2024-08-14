/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:03:39 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 11:50:07 by emedeiro         ###   ########.fr       */
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

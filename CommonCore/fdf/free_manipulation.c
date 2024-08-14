/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:02:18 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 12:27:03 by emedeiro         ###   ########.fr       */
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
void    exit_free(t_fdf *fdf)
{
    free_fdf(fdf);
    exit(EXIT_FAILURE);
}

char	*ft_free_res(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
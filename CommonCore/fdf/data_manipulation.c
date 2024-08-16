/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:20:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/15 14:21:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map   *ft_data(char *file)
{
	t_map   *map;
	char	*line;
	int     x;
	int     y;

	x = 0;
	y = 0;
	if (dimensions(&x, &y, file) == -1)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = x;
	map->height = y;
map->matrix = malloc(map->height * sizeof(t_point *));	if (!map->matrix)
		return (NULL);
	line = read_map(file, map);
	if (!line)
		return (NULL);
	return (map);
}
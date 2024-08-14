/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:20:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 12:27:13 by emedeiro         ###   ########.fr       */
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
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = x;
	map->height = y;
	map->matrix = (t_point **)malloc(sizeof(t_point *) * y);	
	if (!map->matrix)
		return (NULL);
	line = read_map(file, map);
	if (!line)
		return (NULL);
	return (map);
}
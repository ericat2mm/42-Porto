/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_dots_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:50:12 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:31:35 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**create_malloc_matrix(int rows, int cols)
{
	t_point		**matrix;
	int			i;

	matrix = (t_point **)malloc(sizeof(t_point *) * (rows + 1));
	if (!matrix)
		get_err(MALLOC_ERR);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (t_point *)malloc(sizeof(t_point) * (cols + 1));
		if (!matrix[i])
		{
			while (i > 0)
				free(matrix[--i]);
			free(matrix);
			get_err(MALLOC_ERR);
		}
		i++;
	}
	matrix[rows] = NULL;
	return (matrix);
}

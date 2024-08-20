/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:00:16 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:46:02 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_resources(t_fdf *data)
{
	int	i;

	if (data)
	{
		if (data->matrix)
		{
			i = 0;
			while (data->matrix[i])
			{
				free(data->matrix[i]);
				i++;
			}
			free(data->matrix);
		}
		free(data);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:00:16 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 17:43:51 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_resources(t_fdf *data)
{
    if (data)
    {
        if (data->matrix)
        {
            int i = 0;
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
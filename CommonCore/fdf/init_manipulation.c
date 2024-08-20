/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 16:18:32 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_controller(t_fdf *data, t_point **matrix)
{
	data->matrix = matrix;
	data->map_largenest = get_map_largenest(matrix); //we need to scale the map
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->is_isometric = 1;
	data->random_color = 0;
	data->angle = 0.663599; //why 35?? because it's the best angle to view the map
	data->win_x = 1300;
	data->win_y = 800;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->color_style = 1;
	data->mlx_ptr = mlx_init();
	data->has_colors = is_map_has_colors(matrix);
	if (!data->mlx_ptr)
		get_err(MLX_ERR);
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	if (!data->win_ptr)
		get_err(WIN_ERR);
}
int	get_map_largenest(t_point **matrix)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (!matrix[y][x].is_last)
		x++;
	while (matrix[y])
		y++;
	return (y + x);
}
double	get_scale(t_fdf *data)
{
	if (data->map_largenest < 100)
		return (3);
	if (data->map_largenest < 200)
		return (1.5);
	if (data->map_largenest < 400)
		return (1);
	if (data->map_largenest < 500)
		return (0.5);
	if (data->map_largenest < 700)
		return (0.4);
	if (data->map_largenest < 900)
		return (0.3);
	return (0.2);
}
double	get_z_scale(t_fdf *data)
{
	if (data->map_largenest < 50)
		return (1.3);
	if (data->map_largenest < 100)
		return (1);
	if (data->map_largenest < 300)
		return (0.5);
	if (data->map_largenest < 500)
		return (0.4);
	if (data->map_largenest < 700)
		return (0.3);
	if (data->map_largenest < 900)
		return (0.2);
	return (0.1);
}

int	is_map_has_colors(t_point **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (!matrix[i][j].is_last)
		{
			if (matrix[i][j].color != -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
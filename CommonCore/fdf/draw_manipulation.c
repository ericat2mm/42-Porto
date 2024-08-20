/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:12 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:56:36 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_point **matrix, t_fdf *data)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				draw_line(matrix[y][x], matrix[y + 1][x], data);
			if (!matrix[y][x].is_last)
				draw_line(matrix[y][x], matrix[y][x + 1], data);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	push_image_to_window(data);
	menu(data);
}

void	draw_line(t_point a, t_point b, t_fdf *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_coordinates(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = max_value(abs_value(step_x), abs_value(step_y));
	step_x /= max;
	step_y /= max;
	color = get_color(param, a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
		if (coordinates_x(a.x, param) < param->win_x && \
		coordinates_y(a.y, param) < param->win_y)
			my_mlx_pixel_put(&param->img, coordinates_x(a.x, param), \
			coordinates_y(a.y, param), color);
		a.x += step_x;
		a.y += step_y;
	}
}

void	push_image_to_window(t_fdf *data)
{
	void	*previous_image;

	previous_image = data->img.img;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, previous_image);
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	menu(t_fdf *param)
{
	char	*menu;

	menu = "n -> GET BACK TO INITIAL STATE";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 10, 0xffffff, menu);
	menu = "1 -> SWITCHING BETWEEN 3D/2D MODES";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 45, 0xffffff, menu);
	menu = "o OR - -> ZOOM IN OR ZOOM OUT";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 80, 0xffffff, menu);
	menu = "8 OR 2 OR c -> COLORS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 150, 0xffffff, menu);
	menu = "4 OR 6 -> KEYS FOR ROTATING THE MODEL";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 185, 0xffffff, menu);
	menu = "w s d a -> MOVE PICTURE LIKE ARROW KEYS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 220, 0xffffff, menu);
}

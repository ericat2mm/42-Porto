/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:59 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:40:56 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point		**matrix;
	t_fdf		*data;

	data = NULL;
	if (argc != 2)
		get_err(INPUT_ERR);
	if (!is_extension_valid(argv[1]))
		get_err(EXTENSION_ERR);
	matrix = parse_map(argv[1]);
	if (matrix == NULL)
	{
		free(matrix);
		get_err(MALLOC_ERR);
	}
	printf(LOGO);
	data = (t_fdf *) alloc_mem(1, sizeof(t_fdf));
	init_controller(data, matrix);
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	draw(matrix, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, catch_events, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_window, data);
	mlx_loop(data->mlx_ptr);
}

int	close_window(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (data->img.img)
		mlx_destroy_image(data->mlx_ptr, data->img.img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_resources(data);
	exit(EXIT_SUCCESS);
}

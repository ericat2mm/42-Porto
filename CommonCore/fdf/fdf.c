/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:59 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 16:24:24 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point		**matrix;
	t_fdf	*data;

	data = NULL;
    if (argc != 2)
        get_err(INPUT_ERR);
    if(!is_extension_valid(argv[1]))
         get_err(EXTENSION_ERR);
	matrix = parse_map(argv[1]);
	
	if(matrix == NULL)
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
	mlx_loop(data->mlx_ptr);
}

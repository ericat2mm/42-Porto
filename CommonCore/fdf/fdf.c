/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:21:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/18 12:40:35 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
    t_point	**matrix;
    t_fdf	*data;
    
    if (argc != 2)
		get_err(INPUT_ERR);
	else if (!is_extension_valid(argv[1]))
		get_err(EXTENSION_ERR);
	matrix = parse_map(argv[1]);
	printf(LOGO);
    data = (t_fdf *)malloc(sizeof(t_fdf));
    if (data == NULL)
        get_err(MALLOC_ERR);
	init_controller_of_image(data, matrix);
    data->img.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.size_l, &data->img.endian);
	draw(matrix, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, catch_events, data);
	mlx_loop(data->mlx_ptr);
}

//ft_exit function
int		ft_exit(t_fdf *data)
{
    free(data);
    exit(EXIT_SUCCESS);
}

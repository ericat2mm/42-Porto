/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:43 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:49:03 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_exit(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (data)
	{
		free_resources(data);
		free(data);
	}
	ft_putstr_fd(END_MSG, 2);
	free(data);
	exit(EXIT_SUCCESS);
}

int	catch_events(int key, t_fdf *data)
{
	if (is_key(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		do_key(key, data);
		menu(data);
		draw(data->matrix, data);
	}
	if (key == 65307)
	{
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
	return (0);
}

void	do_key(int key, t_fdf *data)
{
	scale_events(key, data);
	if (key == 'w')
		data->shift_y -= 10;
	if (key == 's')
		data->shift_y += 10;
	if (key == 'a')
		data->shift_x -= 10;
	if (key == 'd')
		data->shift_x += 10;
	if (key == '1')
		data->is_isometric = !data->is_isometric;
	if ((key == 'z') && data->is_isometric)
		data->angle += 0.07;
	if ((key == 'x') && data->is_isometric)
		data->angle -= 0.07;
	if (key == 'n')
		get_back_to_normal_state(data);
	if (key == 'c')
		set_color_styles(data);
}

void	scale_events(int key, t_fdf *data)
{
	if (key == 'o')
		data->scale += get_scale(data);
	if (key == '-')
		data->scale -= get_scale(data);
	if ((key == 's') && data->is_isometric)
		data->z_scale += get_z_scale(data);
	if ((key == 'w') && data->is_isometric)
		data->z_scale -= get_z_scale(data);
}

void	get_back_to_normal_state(t_fdf *data)
{
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->angle = 0.563599;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
}

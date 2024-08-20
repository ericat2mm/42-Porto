/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:43 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 14:11:32 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_exit(t_fdf *data)
{
	free(data);
	ft_putstr_fd(END_MSG, 2);
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
	if (key == '5')
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_exit(data);
	}
	return (0);
}

void	do_key(int key, t_fdf *data)
{
	scale_events(key, data);
	if (key == '~')
		data->shift_y -= 10;
	if (key == '}')
		data->shift_y += 10;
	if (key == '{')
		data->shift_x -= 10;
	if (key == '|')
		data->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		data->is_isometric = !data->is_isometric;
	if ((key == 86 || key == 21) && data->is_isometric)
		data->angle += 0.07;
	if ((key == 88 || key == 22) && data->is_isometric)
		data->angle -= 0.07;
	if (key == 36)
		get_back_to_normal_state(data);
	if (key == 8)
		set_color_styles(data);
}
void	scale_events(int key, t_fdf *data)
{
	if (key == 24 || key == 69)
		data->scale += get_scale(data);
	if (key == 27 || key == 78)
		data->scale -= get_scale(data);
	if ((key == 91 || key == 28) && data->is_isometric)
		data->z_scale += get_z_scale(data);
	if ((key == 84 || key == 19) && data->is_isometric)
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
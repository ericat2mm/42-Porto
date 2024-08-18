/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:21:17 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 00:31:15 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		catch_events(int key, t_fdf *data)
{
    choose_key(key, data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    do_key(key, data);
    menu(data);
    draw(data->matrix, data);
    return (0);
}
//choose_key function
void	choose_key(int key, t_fdf *data)
{
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
}
void	get_back_to_normal_state(t_fdf *data)
{
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->angle = 0.563599;
	data->shift_x = data->width / 3;
	data->shift_y = data->height / 3;
}
//do_key functio
void	do_key(int key, t_fdf *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    if (key == 69)
        data->z_scale += 0.1;
    if (key == 78)
        data->z_scale -= 0.1;
    if (key == 8)
        data->color = !data->color;
}
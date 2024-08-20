/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:08 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 12:30:01 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coordinates(t_point *a, t_point *b, t_fdf *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
float	abs_value(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	max_value(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

int	coordinates_x(float x, t_fdf *data)
{
	if ((int)round(x) >= data->win_x)
		return ((int) x);
	return ((int) round(x));
}

int	coordinates_y(float y, t_fdf *data)
{
	if ((int) round(y) >= data->win_y)
		return ((int) y);
	return ((int) round(y));
}
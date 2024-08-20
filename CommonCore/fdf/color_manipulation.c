/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:20 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:36:17 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_fdf *params, t_point a, t_point b)
{
	if (params->color_style == 4)
		return (colors_mode5(a, b));
	if (params->color_style == 3)
		return (colors_mode4(params, a, b));
	if (params->color_style == 2)
		return (colors_mode3(params, a, b));
	if (params->color_style == 1)
		return (colors_mode2(a, b));
	else
		return (colors_mode1(a, b));
	return (0);
}

int	get_random_color(void)
{
	int	random;

	random = rand() % MAX_COLOR_HEX;
	return (random);
}

int	get_random_white_color(void)
{
	int	arr[6];

	arr[0] = 0xfffafa;
	arr[1] = 0xEEEEFF;
	arr[2] = 0xfdfcfa;
	arr[3] = 0xf5f5f5;
	arr[4] = 0xe5e4e2;
	arr[5] = 0xfffafa;
	return (arr[rand() % 6]);
}

void	set_color_styles(t_fdf *data)
{
	data->color_style = (data->color_style + 1) % (4 + data->has_colors);
	data->random_color = 0;
	data->random_color2 = 0;
}

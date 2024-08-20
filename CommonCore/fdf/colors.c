/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:20 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 13:07:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors_mode1(t_point a, t_point b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_color());
	if (b.z != a.z)
		return (get_random_color());
	return (get_random_white_color());
}

int	colors_mode2(t_point a, t_point b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_white_color());
	if (b.z != a.z)
		return (get_random_white_color());
	return (get_random_color());
}

int	colors_mode3(t_fdf *params, t_point a, t_point b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = get_random_color();
		return (params->random_color);
	}
	return (get_random_white_color());
}

int	colors_mode4(t_fdf *params, t_point a, t_point b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = get_random_color();
		return (params->random_color);
	}
	if (params->random_color2)
		return (params->random_color2);
	params->random_color2 = get_random_color();
	return (params->random_color2);
}

int	colors_mode5(t_point a, t_point b)
{
	if (a.color >= 0)
		return (a.color);
	else if (b.color >= 0)
		return (b.color);
	return (0xFFFFFF);
}
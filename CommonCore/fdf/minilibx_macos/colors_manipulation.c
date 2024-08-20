/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:34:14 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 12:34:39 by emedeiro         ###   ########.fr       */
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

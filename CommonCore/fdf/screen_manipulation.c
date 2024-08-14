/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 07:45:21 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/14 07:53:39 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    screen_settings(t_fdf *win)
{
    mlx_string_put(win->mlx, win->win, 10, 10, 0xFFFFFF, "Zoom: + -");
    mlx_string_put(win->mlx, win->win, 10, 30, 0xFFFFFF, "Move: Arrows");
    mlx_string_put(win->mlx, win->win, 10, 90, 0xFFFFFF, "Exit: ESC");
    mlx_string_put(win->mlx, win->win, 10, 110, 0xFFFFFF, "Page Up: 5 3");
}
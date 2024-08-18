/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:01:02 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/18 12:37:02 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw(t_point **matrix, t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (matrix[y])
    {
        x = 0;
        while (1)
        {
            if (matrix[y + 1])
                draw_line(matrix[y][x], matrix[y + 1][x], data);
            if (!matrix[y][x].is_last)
                draw_line(matrix[y][x], matrix[y][x + 1], data);
            if (matrix[y][x].is_last)
                break;
            x++;
        }
        y++;
    }
    push_image_to_win(data);
    menu(data);
}

void draw_line(t_point p0, t_point p1, t_fdf *data)
{
    float delta_x;
    float delta_y;
    float max;
    int color;

    set_coordinates(&p0, &p1, data);
    delta_x = p1.x - p0.x;
    delta_y = p1.y - p0.y;
    max = fmax(fabs(delta_x), fabs(delta_y));
    delta_x /= max;
    delta_y /= max;
    color = get_color(data, p0, p1);
    while ((int)(p0.x - p1.x) || (int)(p0.y - p1.y))
    {
        if (p0.x > data->width || p0.y > data->height || p0.x < 0 || p0.y < 0)
            break;
        if (coordinate_x(p0.x, data) < data->width && coordinate_y(p0.y, data) < data->height)
            put_pixel(&data->img, coordinate_x(p0.x, data), coordinate_y(p0.y, data), color);
        p0.x += delta_x;
        p0.y += delta_y;
    }
}
void push_image_to_win(t_fdf *data)
{
    void *previous_image;

    previous_image = data->img.img;
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, previous_image);
    data->img.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.size_l, &data->img.endian);
}
void menu(t_fdf *data)
{
    int y;

    y = 0;
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 20, 0xFFFFFF, "How to use:");
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 30, 0xFFFFFF, "Zoom: Scroll mouse");
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 30, 0xFFFFFF, "Move: Arrows");
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 30, 0xFFFFFF, "Change projection: I");
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 30, 0xFFFFFF, "Change color: C");
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y += 30, 0xFFFFFF, "Exit: ESC");
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}
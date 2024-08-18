/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:32:59 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 00:30:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_controller_of_image(t_fdf *data, t_point **matrix)
{
    data->matrix = matrix;
    data->scale = get_scale(data);
    data->z_scale = get_z_scale(data);
    data->is_isometric = 1;
    data->color = 1;
    data->shift_x = data->width / 3; // 3 because the map is centered
    data->shift_y = data->height / 3;   
    data->width = 1300;
    data->height = 800;
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        get_err(MLX_ERR);
    data->has_colors = map_has_colors(matrix);
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "FdF");
    if (data->win_ptr == NULL)
        get_err(MLX_ERR);
}
int map_has_colors(t_point **matrix)
{
    int y;
    int x;

    y = 0;
    while (matrix[y])
    {
        x = 0;
        while (!matrix[y][x].is_last)
        {
            if (matrix[y][x].color != -1)
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}

double get_scale(t_fdf *data)
{
    double scale_x;
    double scale_y;
    double scale;

    scale_x = data->width / (ft_wordcount((char *)data->matrix[0], ' ') - 1);
    scale_y = data->height / ft_wordcount((char *)data->matrix, '\0');
    scale = fmin(scale_x, scale_y);
    return (scale);
}
//ft_wordcount function
int ft_wordcount(char *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }
    return (count);
}

double get_z_scale(t_fdf *data)
{
    double z_scale;
    int y;
    int x;

    y = 0;
    z_scale = 0;
    while (data->matrix[y])
    {
        x = 0;
        while (!data->matrix[y][x].is_last)
        {
            if (data->matrix[y][x].z > z_scale)
                z_scale = data->matrix[y][x].z;
            x++;
        }
        y++;
    }
    return (z_scale);
}

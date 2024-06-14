/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:30:27 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:48 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include "minilibx_macos/mlx.h"

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
    struct s_point *next;
} t_point;

typedef struct s_map
{
    int width;
    int height;
    t_point *point;
} t_map;

t_map *read_file(char *filename);
void draw_map(t_map *map);
void multiplication_of_matrix(double RM_x[3][3], double RM_y[3][3], double RM[3][3]);
void matrix_multiplication_by_point(t_point *point, double RM[3][3]);
void projection_point(t_point *point);
t_map *create_map();
t_map *parse_file(char *filename, t_map *map);
void draw_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr);
int ft_abs(int value);

#endif

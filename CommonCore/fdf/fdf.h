/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:48:47 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/19 00:34:19 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "defines.h"

typedef struct	s_point
{
    int		x;
    int		y;
    int		z;
    int		color;
    int		is_last;
}				t_point;

typedef struct	s_img
{
    void	*img;
    char	*addr; // address of the first byte of the image
    int		size_l;
    int		bpp;
    int		endian; // endian: 0 for little-endian, 1 for big-endian
}				t_img;

typedef struct	s_fdf
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_img     img;
    t_point	**matrix;
    t_img    background;
    int        width;
    int        height;
    double angle; // angle of rotation
    int is_isometric; // is the projection isometric?
    int shift_x; // shift for x-axis
    int shift_y; // shift for y-axis
    double z_scale; // scale for z-axis
    double scale; // scale for x and y axis
    int has_colors; // does the map have color info?
    int color; // color of the line
}				t_fdf;

//COLOR_MANIPULATION
int get_color_from_line(char *s);
int ft_atoi_base(char *s);

//DRAW_MANIPULATION
void draw(t_point **matrix, t_fdf *data);
void draw_line(t_point p0, t_point p1, t_fdf *data);
void push_image_to_win(t_fdf *data);
void menu(t_fdf *data);
void	put_pixel(t_img *data, int x, int y, int color);

//DRAW_UTILS
int get_color(t_fdf *data, t_point p0, t_point p1);
int coordinate_x(float x, t_fdf *data);
int coordinate_y(float y, t_fdf *data);
void set_coordinates(t_point *p0, t_point *p1, t_fdf *data);
void isometric(t_point *p, float angle);

//ERROR_MANIPULATION
void	get_err(char *err);
int		is_extension_valid(char *file);

//FDF
int		ft_exit(t_fdf *data);

//INIT_MANIPULATION
void init_controller_of_image(t_fdf *data, t_point **matrix);
int map_has_colors(t_point **matrix);
double get_scale(t_fdf *data);
double get_z_scale(t_fdf *data);
int ft_wordcount(char *s, char c);

//KEY_MANIPULATION
int		catch_events(int key, t_fdf *data);
void	choose_key(int key, t_fdf *data);
void	get_back_to_normal_state(t_fdf *data);
void	do_key(int key, t_fdf *data);

//PARSE_MANIPULATION
t_point **parse_map(char *file);
void parse_line(t_point **matrix, char *line);
void is_number_valid(char *s);

//ZOOM
void	zoom(t_point *a, t_point *b, t_fdf *param);
#endif
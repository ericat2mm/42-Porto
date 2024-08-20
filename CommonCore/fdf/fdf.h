/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:26 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 11:26:12 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx-linux/mlx.h"
#include "defines.h"

# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			is_last;
	int			color;
}				t_point;

typedef struct s_image 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fdf
{
	double			scale;
	int				color_style;
	int				random_color;
	int				random_color2;
	int				map_largenest;
	int				has_colors;
	double			z_scale;
	int				shift_x;
	int				shift_y;
	int				is_isometric;
	double			angle;
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			**matrix;
	t_image			img;
	t_image			banner;
}	t_fdf;

//COLORS
int	colors_mode1(t_point a, t_point b);
int	colors_mode2(t_point a, t_point b);
int	colors_mode3(t_fdf *params, t_point a, t_point b);
int	colors_mode4(t_fdf *params, t_point a, t_point b);
int	colors_mode5(t_point a, t_point b);

//COLOR_MANIPULATION
int	get_color(t_fdf *params, t_point a, t_point b);
int	get_random_color(void);
int	get_random_white_color(void);
void	set_color_styles(t_fdf *data);

//DRAW_MANIPULATION
void	draw(t_point **matrix, t_fdf *data);
void	draw_line(t_point a, t_point b, t_fdf *param);
void	push_image_to_window(t_fdf *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	menu(t_fdf *param);

//DRAW_UTIL
void	set_coordinates(t_point *a, t_point *b, t_fdf *param);
float	abs_value(float x);
float	max_value(float x, float y);
int	coordinates_x(float x, t_fdf *data);
int	coordinates_y(float y, t_fdf *data);

//DRAW_UTIL2
void	isometric(t_point *dot, double angle);
void	zoom(t_point *a, t_point *b, t_fdf *param);

//ERROR_MANIPULATION
int	is_extension_valid(const char *s);
void	get_err(const char *err);
int	open_file(char *file_name, int permissions);
int	ft_strcmp(const char *s1, const char *s2);
void	*alloc_mem(size_t size, size_t size_of);

//INIT_MANIPULATION
void	init_controller(t_fdf *data, t_point **matrix);
int	get_map_largenest(t_point **matrix);
double	get_scale(t_fdf *data);
double	get_z_scale(t_fdf *data);
int	is_map_has_colors(t_point **matrix);

//KEY_MANIPULATION
int	ft_exit(t_fdf *data);
int	catch_events(int key, t_fdf *data);
void	do_key(int key, t_fdf *data);
void	scale_events(int key, t_fdf *data);
void	get_back_to_normal_state(t_fdf *data);

//KEY_MANIPULATION.2
int	is_key(int key);

//PARSE_MANIPIULATION
t_point	**parse_map(char *file_name);
t_point	**allocate_dots(char *file_name);
int	get_dots(char *line, t_point **matrix, int y);
void	is_number_valid(char *s);
int	ft_wdcounter(char const *s, char c);

//PARSE_UTILS
int	in_string(char *s, char c);
char	to_lower(char c);
int	get_color_line(char *s);
int	hex_to_int(char *s);
int	index_of(char *s, char c);

//ZOOM
void	zoom(t_point *a, t_point *b, t_fdf *param);

#endif
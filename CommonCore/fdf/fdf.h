/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:40:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/13 15:32:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <math.h>


#define WIN_WIDTH 1920 //because it's the resolution of my screen
#define WIN_HEIGHT 1080


typedef struct  s_map
{
    int **matrix;
    int width;
    int height;
    int zoom;
}   t_map;

typedef struct  s_point
{
    int x;
    int y;
    int z;
    int color;
}   t_point;

typedef struct  s_image
{
    void    *img;
    char    *data;
    int     size_l;
    int     bpp;
    int     endian;
}   t_image;

typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    t_map   *map; // pointer to the map struct
    t_image *img;
    int     zoom;
    int   view;
}   t_fdf;

//MAIN
int check_args(int argc, char **argv);
char	*read_file(int fd, char *res);

//DRAW_MANIPULATION.C
void draw_line(int x_a, int y_a, int x_b, int y_b, t_fdf *fdf);
void draw_line_low(int x_a, int y_a, int x_b, t_fdf *fdf, int delta_x, int delta_y);
void draw_line_high(int x_a, int y_a, int y_b, t_fdf *fdf, int delta_x, int delta_y);

//FREE_MANIPULATION.C
void    free_map(t_map *map);
void   free_fdf(t_fdf *fdf);

//INIT_MANIPULATION.C
t_map   *init_map(void);
t_fdf   *init_fdf(t_map *map);

//KEY_MANIPULATION.C
int key_hook(int keycode, t_fdf *fdf);
int mouse_hook(int button, t_fdf *fdf);

//READ_MANIPULATION.C
char    *read_map(char *file, t_map *map);

//RENDER_MANIPULATION.C
void    render(t_fdf *fdf);
void    background(t_image *img, int color);





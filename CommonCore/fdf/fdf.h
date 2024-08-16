#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

#define WIN_WIDTH 1024 //because it's the resolution of my screen
#define WIN_HEIGHT 1024

typedef struct s_map t_map;

typedef struct s_point
{
    float x;
    float y;
    int z;
    int color;
    int value;
    t_map *map;
} t_point;

typedef struct s_image
{
    void    *img;
    char    *data;
    int     size_l;
    int     bpp;
    int     endian;
    char    *addr;
} t_image;

typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_image img;
    double     view;
    void   *mlx_connect;
    void   *mlx_win;
    int     data;
} t_fdf;

typedef struct s_map
{
    t_point **matrix;
    t_fdf   *fdf;
    int width;
    int height;
    int x_offset;
    int y_offset;
    int     alpha;
    int     beta;
} t_map;

//BRESENHAM_UTILS.C
float step_one(t_point *point_1, t_point *point_2);
float step_one_two(t_point *point_1, t_point *point_2);
float step_two(float dx, float dy, float max);
float step_two_two(float dx, float max);
float step_two_three(float dy, float max);

//DATA_MANIPULATION.C
t_map   *ft_data(char *file);

//DIMENSINS.C
int dimensions(int *x, int *y, char *file);
int count_words(char *s, char c);

//DRAW_MANIPULATION.C
int draw(t_fdf *win);
void bresenham_algorithm(t_point *point_1, t_point *point_2, t_fdf *win);
void isometric(float *x, float *y, int z);
void apply_isometric(t_point *point_1, t_point *point_2, t_fdf *win);

//MAIN
int check_args(int argc, char **argv);
void	print_map(t_fdf *fdf);

//FREE_MANIPULATION.C
void    free_map(t_map *map);
void   free_fdf(t_fdf *fdf);
void    exit_free(t_fdf *fdf);

//INIT_MANIPULATION.C
t_map   *init_map(void);
t_fdf   *init_fdf(t_map *map);

//KEY_MANIPULATION.C
//int key_hook(int keycode, t_fdf *fdf);
int     exit_hook(t_fdf *fdf);

//MATRIX_MANIPULATION.C
void    matrix(t_point *row, char *line, int y);

//POINT_MANIPULATION.C
void    point(t_point *point, char *coords, int x, int y);

//READ_MANIPULATION.C
char    *read_map(char *file, t_map *map);
//RENDER_MANIPULATION.C
void render(t_fdf *fdf);
void    background(t_image *img, int color);
void	img_pix_put(t_image *img, int x, int y, int color);

//SCREEN_SETTINGS.C
void    screen_settings(t_fdf *win);
#endif

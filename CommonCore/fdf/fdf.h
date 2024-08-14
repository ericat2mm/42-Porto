#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

#define WIN_WIDTH 2560 //because it's the resolution of my screen
#define WIN_HEIGHT 1600

// Forward declaration
typedef struct s_map t_map;

typedef struct s_point
{
    int x;
    int y;
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
    t_image *img;
    int     view;
    void   *mlx_connect;
    void   *mlx_win;
    int     data;
} t_fdf;

typedef struct s_map
{
    t_point **matrix;
    int width;
    int height;
    int zoom;
    int z_divisor;
    int z_range;
    int x_offset;
    int y_offset;
    int view;
    int     alpha;
    int     beta;
} t_map;
typedef struct s_mlx
{
	void	*mlx_connect;
	void	*mlx_win;
	t_map	*map;
	t_image	img;
    t_fdf   *win;
}	t_mlx;

//BRESENHAM_UTILS.C
float step_one(float *x_a, float *x_b);
float step_one_two(float *y_a, float *y_b);
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
void    bresenham_algorithm(float x_a, float y_a, float x_b, float y_b, t_fdf *win);
void isometric(float *x, float *y, float z);
void apply_isometric(t_fdf *win, float *x_a, float *y_a, float *x_b, float *y_b);

//MAIN
int check_args(int argc, char **argv);

//FREE_MANIPULATION.C
void    free_map(t_map *map);
void   free_fdf(t_fdf *fdf);
void    exit_free(t_fdf *fdf);

//INIT_MANIPULATION.C
t_map   *init_map(void);
t_fdf   *init_fdf(t_map *map);

//KEY_MANIPULATION.C
int key_hook(int keycode, t_fdf *fdf);
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

//SCREEN_SETTINGS.C
void    screen_settings(t_fdf *win);
#endif

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define WHT "\x1B[37m"
#define YEL "\x1B[33m"
#define WIDTH 800
#define HEIGHT 640
#define IM_RATIO
// #define IMG_WIDTH 640
// #define IMG_HEIGHT 800

typedef struct s_data
{
	// double		x;
	// double		y;
	int			xp;
	int			yp;
	double		x1;
	double		y1;
	double		xdelta;
	double		ydelta;
	double		i;
	double		j;
	int			img_width;
	int			img_height;
	double		im_ratio;
	double 		re_av;
	double 		im_av;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zx;
	double		zy;
	double		c_re;
	double		c_im;
	double		new_re;
	double		new_im;
	int			iter;
	int			max_iter;
	double 		re_factor;
	double 		im_factor;
	mlx_image_t	*img;
	mlx_t 		*mlx;
	void (*f)(struct s_data *);
}				t_data;

// struct qui stocl les complex
typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;


// struct qui stock ce qui a rapport a la MLX
typedef struct	s_mlx 
{
	mlx_image_t	*img;
	mlx_t 		*mlx;
}				t_mlx;

// struct principale
typedef struct s_fractol 
{
	t_complex	c;
	t_complex	c_julia;
	t_complex	c_max;
	t_complex	c_min;
	t_complex	scale;
	size_t		iter;
	size_t		max_iter;
	//t_funcptr	fractal_func;
	uint8_t		color_shift;
	int			*color_scheme;
	//bool		is_fixed;
}	t_fractol;

int	get_rgba(int r, int g, int b, int a);
uint32_t set_color(int iter);

void	ft_mandelbrot(t_data *fr_data);
// void	ft_julia(t_data *fr_data);
// void* calculate_pixel(void* arg);
void ft_julia(t_data *fr_data);
void get_arg(int argc, char **argv);

double 		my_atof(const char* str);
void 		arg_usage(int flag);
int			print_usage(void);
t_data		*get_data(char c, char *arg1, char *arg2);

void	my_keyhook(mlx_key_data_t keydata, void *param);
void 	my_scrollhook(double xdelta, double ydelta, void* param);
void	my_mouse_pos(double xpos, double ypos, void* param);

#endif
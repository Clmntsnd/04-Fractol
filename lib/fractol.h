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

typedef struct s_fr_data
{
	double		x;
	double		y;
	double		i;
	double		j;
	double		img_width;
	double		img_height;
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
	pthread_mutex_t mutex;

}				t_fr_data;

int	get_rgba(int r, int g, int b, int a);
uint32_t set_color(int c);

void	ft_mandelbrot(t_fr_data *fr_data);
void	ft_julia(t_fr_data *fr_data);

t_fr_data	*get_data();

void	my_keyhook(mlx_key_data_t keydata, void *param);
void 	my_scrollhook(double xdelta, double ydelta, void* param);

#endif
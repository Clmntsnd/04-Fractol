#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define WHT "\x1B[37m"
#define YEL "\x1B[33m"
#define WIDTH 600
#define HEIGHT 400

typedef struct s_fr_data
{
	double		x;
	double		y;
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
	mlx_image_t	*img;

}				t_fr_data;

/*
// Print the window width and height.
static void	ft_hooks(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

*/

int	get_rgba(int r, int g, int b, int a);

int set_color(int c);

void	ft_mandelbrot(t_fr_data *fr_data);

t_fr_data	*get_data();

void	my_keyhook(mlx_key_data_t keydata, void *param);

#endif
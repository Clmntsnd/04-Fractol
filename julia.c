#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1200	
#define HEIGHT 800

// mlx_image_t	*g_img;

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

void	ft_julia(mlx_image_t* img)
{
	/*
	**	These variables are used to loop over the pixels of the image. 
	**	i is the index of the current column, and j is the index of the current row.
	*/
	int		i, j;
	
	/*
	**	These variables are used to store the real and imaginary components 
	**	of the current point being tested for membership in the Mandelbrot set.
	*/
	double	x, y;

	/*
	**	These variables define the range of x and y values that will be used 
	**	to calculate the set. 
	**	They determine the portion of the complex plane that will be drawn.
	*/	
	double xmin, xmax, ymin, ymax;

	/*
	**	This variable specifies the maximum number of iterations that the 
	**	program will perform when testing a point for membership in the
	**	Mandelbrot set.
	*/
	int		max_iter;

	/*
	**	These variables are used to store the real and imaginary components 
	**	of the current value of z in the Mandelbrot set equation z_n+1 = z_n^2 + c.
	*/
	double 	zx, zy;

	/*
	**	These variables are used to store the real (re) and imaginary (im) components 
	**	of the constant c in the Mandelbrot set equation.
	*/
	double c_re, c_im;
	
	/*
	**	These variables are used to store the real (re) and imaginary (im) components 
	**	of the transformed value of z in the Mandelbrot set equation.
	*/
	double new_re, new_im;

	/*
	**	This variable is used to store the color of the current pixel. 
	**	The value of color is determined by the number of iterations performed before 
	**	the magnitude of z becomes greater than or equal to 2 (which is considered to be 
	**	the threshold for divergence).
	*/
	int color;

	xmin = -1.5;
	xmax = 1.5;
	ymin = -1.5;
	ymax = 1.5;
	max_iter = 10000;

	c_re = 0.285;
	c_im = -0.01;
	//0.285 + 0.01i

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x = xmin + i * (xmax - xmin) / WIDTH;
			y = ymin + j * (ymax - ymin) / HEIGHT;

			zx = x;
			zy = y;

			color = 0;
			while (zx * zx + zy * zy < 4 && color < max_iter)
			{
				new_re = zx * zx - zy * zy + c_re;
				new_im = 2 * zx * zy + c_im;
				zx = new_re;
				zy = new_im;
				color++;
			}
			mlx_put_pixel(img, i, j, color * 10000 / max_iter);
			j++;
		}
		i++;
	}
}

int32_t	main(void)
{
	//mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t*	mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "Julia set", true);
	if (!mlx)
		ft_error();

	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	ft_julia(img);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

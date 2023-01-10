#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1200	
#define HEIGHT 800

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/*
// Print the window width and height.
static void ft_hooks(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
*/

typedef struct s_fr_data
{
	double	x;
	double	y;
	double xmin;
	double xmax;
	double ymin;
	double ymax;

	// xmin = -2;
	// xmax = 1;
	// ymin = -1;
	// ymax = 1;
	// max_iter = 128;
	
} t_fr_data;

/*
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fr_data *fr_data;

	
	// If we PRESS the 'UP' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");
	

	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{		
		fr_data->xmin += .1;
		fr_data->ymin += .1;

	}
}
*/

void	ft_mandelbrot(mlx_image_t* img)
{
	t_fr_data fr_data;

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
	//t_fr *fr;

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

	fr_data.xmin = -2;
	fr_data.xmax = 1;
	fr_data.ymin = -1;
	fr_data.ymax = 1;
	max_iter = 128;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			fr_data.x = fr_data.xmin + i * (fr_data.xmax - fr_data.xmin) / WIDTH;
			// fr_data->x = fr_data->xmin + i * (fr_data->xmax - fr_data->xmin) / WIDTH;
        	// fr_data->y = fr_data->ymin + j * (fr_data->ymax - fr_data->ymin) / HEIGHT;
        	fr_data.y = fr_data.ymin + j * (fr_data.ymax - fr_data.ymin) / HEIGHT;

            c_re = x;
            c_im = y;
            zx = 0;
            zy = 0;

            color = 0;
            while (zx * zx + zy * zy < 4 && color < max_iter)
            {
                new_re = zx * zx - zy * zy + c_re;
                new_im = 2 * zx * zy + c_im;
                zx = new_re;
                zy = new_im;
                color++;
            }
			mlx_put_pixel(img, i, j, color * 128 / max_iter);
			j++;
		}
		i++;
	}
}

int32_t	main(void)
{
	// This line is for setting the window in maximised state
	//mlx_set_setting(MLX_MAXIMIZED, true); 
	
	mlx_t*	mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot set", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	ft_mandelbrot(img);
	//mlx_loop_hook(mlx, ft_hooks, mlx);
	//mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 1200	
#define HEIGHT 800


static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/*
// Print the window width and height.
static void ft_hooks(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
*/

//a mettre dans un .h
typedef struct s_fr_data
{
	double	x;
	double	y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zx;
	double	zy;
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	int		max_iter;
	mlx_image_t *img;
	
} t_fr_data;

//a mettre dans un .h
void	ft_mandelbrot(t_fr_data *fr_data);

//a mettre dans un .h
t_fr_data *get_data()
{
	static t_fr_data *fr_data;

	if (!fr_data)
	{
		fr_data = malloc(sizeof(t_fr_data)); //memory allocation for the struct
		fr_data->xmin = -2;
		fr_data->xmax = 1;
		fr_data->ymin = -1;
		fr_data->ymax = 1;
		fr_data->max_iter = 128;
	}
	return (fr_data);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fr_data *fr_data;

	fr_data = get_data();
	
	//close program when pressing ESC key
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{		
		exit(0);
	}

	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{		
		fr_data->ymin += .5;
		fr_data->ymax += .5;
		ft_mandelbrot(fr_data);
	}
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{		
		fr_data->ymin -= .5;
		fr_data->ymax -= .5;
		ft_mandelbrot(fr_data);
	}
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{		
		fr_data->xmin += .5;
		fr_data->xmax += .5;
		ft_mandelbrot(fr_data);
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{		
		fr_data->xmin -= .5;
		fr_data->xmax -= .5;
		ft_mandelbrot(fr_data);
	}
}

int set_color(int c)
{
	int color;

	color = 0;
	if (c < 50)
		color = get_rgba(255, 255, 255, 255);
	else if (c >= 50 && c <=100)
		color = get_rgba(255, 0, 255, 255);
	else
		color = get_rgba(0, 0, 0, 255);
	return (color);
}


void	ft_mandelbrot(t_fr_data *fr_data)
{
	int		i;
	int		j;
	int color;

	printf("xmin : %f\n", fr_data->xmin);
	printf("xmax : %f\n", fr_data->xmax);
	printf("ymin : %f\n", fr_data->ymin);
	printf("ymax : %f\n\n", fr_data->ymax);

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			fr_data->x = fr_data->xmin + i * (fr_data->xmax - fr_data->xmin) / WIDTH;
        	fr_data->y = fr_data->ymin + j * (fr_data->ymax - fr_data->ymin) / HEIGHT;

            fr_data->c_re = fr_data->x;
            fr_data->c_im = fr_data->y;
            fr_data->zx = 0;
            fr_data->zy = 0;

            color = 0;
            while (fr_data->zx * fr_data->zx + fr_data->zy * fr_data->zy < 4 && color < fr_data->max_iter)
            {
                fr_data->new_re = fr_data->zx * fr_data->zx - fr_data->zy * fr_data->zy + fr_data->c_re;
                fr_data->new_im = 2 * fr_data->zx * fr_data->zy + fr_data->c_im;
                fr_data->zx = fr_data->new_re;
                fr_data->zy = fr_data->new_im;
                color++;
			}
			//printf("color : %d\n", color);
			mlx_put_pixel(fr_data->img, i, j, set_color(color));
			j++;
		}
		i++;
	}
}

int32_t	main(void)
{
	t_fr_data *fr_data;
	// This line is for setting the window in maximised state
	//mlx_set_setting(MLX_MAXIMIZED, true); 
	
	fr_data = get_data();
	mlx_t*	mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot set", false);
	if (!mlx)
		ft_error();
	fr_data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!fr_data->img || (mlx_image_to_window(mlx, fr_data->img, 0, 0) < 0))
		ft_error();
	ft_mandelbrot(fr_data);
	//mlx_loop_hook(mlx, ft_hooks, mlx);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
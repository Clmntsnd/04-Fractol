#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	ft_mandelbrot(t_fr_data *fr_data)
{
	int		i;
	int		j;
	//int 	color;
	double	xdelta;
	double	ydelta;

	xdelta = fr_data->xmax - fr_data->xmin;
	ydelta = fr_data->ymax - fr_data->ymin;

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
			// fr_data->x = fr_data->xmin + i * xdelta / WIDTH;
        	// fr_data->y = fr_data->ymin + j * ydelta / HEIGHT;

            fr_data->c_re = fr_data->xmin + i * xdelta / WIDTH;
            fr_data->c_im = fr_data->ymin + j * ydelta / HEIGHT;
            fr_data->zx = 0;
            fr_data->zy = 0;
			fr_data->iter = 0;
            //color = 0;
            while (pow(fr_data->zx, 2) + pow(fr_data->zy, 2) < 4 && fr_data->iter < fr_data->max_iter)
            {
                //fr_data->new_re = fr_data->zx * fr_data->zx - fr_data->zy * fr_data->zy + fr_data->c_re;
                fr_data->new_re = pow(fr_data->zx, 2) - pow(fr_data->zy, 2) + fr_data->c_re;
				fr_data->new_im = 2 * fr_data->zx * fr_data->zy + fr_data->c_im;
                fr_data->zx = fr_data->new_re;
                fr_data->zy = fr_data->new_im;
                //color++;
				fr_data->iter++;
			}
			//printf("color : %d\n", color);
			mlx_put_pixel(fr_data->img, i, j, set_color(fr_data->iter));
			j++;
		}
		i++;
	}
}

/*
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
*/
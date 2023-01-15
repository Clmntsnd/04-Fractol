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
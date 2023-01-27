#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

t_fr_data	*get_data(char c, char *arg1, char *arg2)
{
	static t_fr_data	*data;

	if (!data)
	{
		data = (t_fr_data *)malloc(sizeof(t_fr_data));
		// data->x = 0;
		// data->y = 0;
		// data->img_height = 600;
		// data->img_width = 840;
		data->max_iter = 28;
		if (c == '1')
		{
			data->xmin = -2;
			data->xmax = 1;
			data->ymin = -1.2;
			data->ymax = 1.2;
			// data->xdelta = data->xmax - data->xmin;
			// data->ydelta = data->ymax - data->ymin;
		}
		if (c == '2')
		{
			data->xmin = -1.5;
			data->xmax = 1.5;
			data->ymin = -1.5;
			data->ymax = 1.5;
			// data->xdelta = data->xmax - data->xmin;
			// data->ydelta = data->ymax - data->ymin;
			// data->c_re = - 0.70176;
			// data->c_im = 0.3842;
		}
	}
	return (data);
}

/*
## ----- Mandelbrot data ----- ##

	data->xmin = -2;
	data->xmax = 1;
	data->ymin = -1.2;
	data->ymax = 1.2;
*/

/*
## ----- Julia data ----- ##

	data->xmin = -1.5;
	data->xmax = 1.5;
	data->ymin = -1.5;
	data->ymax = 1.5;
*/

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

t_fr_data	*get_data()
{
	static t_fr_data	*fr_data;

	if (!fr_data)
	{
		fr_data = (t_fr_data *)malloc(sizeof(t_fr_data));
		fr_data->x = 0;
		fr_data->y = 0;
		fr_data->img_height = 640;
		fr_data->img_width = 800;
		fr_data->xmin = -1.5;
		fr_data->xmax = 1.5;
		fr_data->ymin = -1.5;
		fr_data->ymax = 1.5;
		fr_data->max_iter = 300;
	}
	return (fr_data);
}

/*
## ----- Mandelbrot data ----- ##

	fr_data->xmin = -2;
	fr_data->xmax = 1;
	fr_data->ymin = -1.2;
	fr_data->ymax = 1.2;
*/

/*
## ----- Julia data ----- ##

	fr_data->xmin = -1.5;
	fr_data->xmax = 1.5;
	fr_data->ymin = -1.5;
	fr_data->ymax = 1.5;
*/
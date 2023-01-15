#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

t_fr_data	*get_data()
{
	static t_fr_data	*fr_data;

	if (!fr_data)
	{
		/*
		fr_data = (t_fr_data *)malloc(sizeof(t_fr_data));
		fr_data->x = 0;
		fr_data->y = 0;
		fr_data->im_ratio = HEIGHT / WIDTH;
		
		fr_data->xmin = -2; //MinRe
		fr_data->xmax = 1; //MaxRe
		fr_data->re_av = fr_data->xmax  - fr_data->xmin;
		fr_data->ymin = -1.2; //MinIm
		fr_data->ymax = (fr_data->ymin + fr_data->re_av) * fr_data->im_ratio; //MaxIm
		fr_data->im_av = fr_data->ymax  - fr_data->ymin;
		
		fr_data->re_factor = fr_data->re_av/(WIDTH-1); //Re_factor
		fr_data->im_factor = fr_data->im_av/(HEIGHT-1); //Im_factor
		
		fr_data->max_iter = 30;
		*/

		fr_data = (t_fr_data *)malloc(sizeof(t_fr_data));
		fr_data->xmin = -2;
		fr_data->xmax = 1;
		fr_data->ymin = -1;
		fr_data->ymax = 1;
		fr_data->max_iter = 128;
	}
	return (fr_data);
}
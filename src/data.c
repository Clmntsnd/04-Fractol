#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

t_fr_data	*get_data()
{
	static t_fr_data	*fr_data;

	if (!fr_data)
	{
		fr_data = (t_fr_data *)malloc(sizeof(t_fr_data));
		fr_data->xmin = -2;
		fr_data->xmax = 1;
		fr_data->ymin = -1;
		fr_data->ymax = 1;
		fr_data->max_iter = 128;
	}
	return (fr_data);
}
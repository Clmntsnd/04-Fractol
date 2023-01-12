#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fr_data	*fr_data;

	fr_data = get_data();
	//close program when pressing ESC key
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(0);
	}
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fr_data->ymin += .002;
		fr_data->ymax += .002;
		ft_mandelbrot(fr_data);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
	{
		fr_data->ymin += .002;
		fr_data->ymax += .002;
		ft_mandelbrot(fr_data);
	}
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		fr_data->ymin -= .002;
		fr_data->ymax -= .002;
		ft_mandelbrot(fr_data);
	}
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		fr_data->xmin += .002;
		fr_data->xmax += .002;
		ft_mandelbrot(fr_data);
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		fr_data->xmin -= .002;
		fr_data->xmax -= .002;
		ft_mandelbrot(fr_data);
	}
}
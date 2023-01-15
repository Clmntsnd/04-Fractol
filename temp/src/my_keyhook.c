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
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			fr_data->ymin += .1;
			fr_data->ymax += .1;
			ft_mandelbrot(fr_data);
		}
		else
		{
			fr_data->ymin += .2;
			fr_data->ymax += .2;
			ft_mandelbrot(fr_data);
		}
	}
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			fr_data->ymin -= .1;
			fr_data->ymax -= .1;
			ft_mandelbrot(fr_data);
		}
		else
		{
			fr_data->ymin -= .2;
			fr_data->ymax -= .2;
			ft_mandelbrot(fr_data);
		}
	}
	
	// If we HOLD the 'UP' key, move image up.
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		fr_data->xmin += .01;
		fr_data->xmax += .01;
		ft_mandelbrot(fr_data);
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		fr_data->xmin -= .01;
		fr_data->xmax -= .01;
		ft_mandelbrot(fr_data);
	}
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
	{
		puts(YEL "\n Key Hooks (all sets)\n");
		puts(WHT "  esc		| Quit program");
		puts("  ⬆		| Move up");
		puts("  ⬇		| Move down");
		puts("  <->		| Move left|right");
		puts("  r		| change colors to "RED"red"WHT);
		puts("  g		| change colors to "GRN"green"WHT);
		puts("  b		| change colors to "BLU"blue"WHT);
		puts("  h		| Show help");
		puts("  mouse wheel	| Zoom in and out");
		puts(YEL "\n Key Hooks (Julia set)\n");
		puts(WHT"  c + mouse mvt	| change values to show different sets");

	}
}
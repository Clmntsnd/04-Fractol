/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/18 14:06:41 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void exec(t_fr_data *fr_data, char *title)
{
	fr_data->mlx = mlx_init(fr_data->img_width, fr_data->img_height, title, false);
	if (!fr_data->mlx)
		ft_error();
	fr_data->img = mlx_new_image(fr_data->mlx, fr_data->img_width, fr_data->img_height);
	if (!fr_data->img || (mlx_image_to_window(fr_data->mlx, fr_data->img, 0, 0) < 0))
		ft_error();
	fr_data->f(fr_data);	
}

int print_usage (void)
{
	printf(RED "\n❌ Uh oh" WHT ", something is missing! See Below.\n\n" WHT);
	printf(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n");
	printf(YEL "\n📝 Available Sets\n");
	printf("  --> 1️⃣  Mandelbrot\n");
	printf("  --> 2️⃣  Julia (*)\n\n");
	printf("(*) For Julia, please provide 2 args :\n");
	printf("\t|-> ./fractol 2 [A] [B]\n");
	printf("\t|-> A and B are floats nb (-2 < A < 2 & -2 < B < 2)\n");
	printf(GRN "\nPlease type the accurate command to start the program \n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fr_data *fr_data;

	if (argc == 1)
		return(print_usage());
	if (argv[1][0])
	{
		fr_data = get_data(argv[1][0]);
		if (argv[1][0] == '1')
		{
			fr_data->f = &ft_mandelbrot;
			exec(fr_data, "Mandelbrot");
		}
		if (argv[1][0] == '2')
		{
			fr_data->f = &ft_julia;
			exec(fr_data, "Julia");
		}
		mlx_key_hook(fr_data->mlx, &my_keyhook, fr_data);
		mlx_scroll_hook(fr_data->mlx, &my_scrollhook, fr_data);
		// mlx_cursor_hook(fr_data->mlx, &my_mouse_pos, fr_data);
		mlx_loop(fr_data->mlx);
		mlx_terminate(fr_data->mlx);
		return (EXIT_SUCCESS);
	}
	return (0);
}

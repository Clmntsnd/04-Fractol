/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/16 17:03:03 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int print_usage (void)
{
	puts(RED "\n❌ Uh oh" WHT ", something is missing! See Below.\n" WHT);
	puts(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n");
	puts(YEL "📝 Available Sets");
	puts("  --> 1️⃣  Mandelbrot");
	puts("  --> 2️⃣  Julia\n");
	puts("    |-> For Julia, please provide 2 args :");
	puts("    |-> ./fractol 2 [A] [B]");
	puts("    |-> A and B are floats nb (-2 < A < 2 & -2 < B < 2)\n");
	puts(GRN "Please type the accurate command to start the program");
	return (1);
}

int	main(int argc, char *argv[])
{
		t_fr_data *fr_data;

	if (argc == 1)
	{
		return(print_usage());
	}
	if (argv[1][0])
	{
		fr_data = get_data();
		if (argv[1][0] == '1')
		{
			fr_data->mlx = mlx_init(fr_data->img_width, fr_data->img_height, "Mandelbrot set", false);
			if (!fr_data->mlx)
				ft_error();
			fr_data->img = mlx_new_image(fr_data->mlx, fr_data->img_width, fr_data->img_height);
			if (!fr_data->img || (mlx_image_to_window(fr_data->mlx, fr_data->img, 0, 0) < 0))
				ft_error();
			ft_mandelbrot(fr_data);
		}
		if (argv[1][0] == '2')
		{
			fr_data->mlx = mlx_init(fr_data->img_width, fr_data->img_height, "Julia set", false);
			if (!fr_data->mlx)
				ft_error();
			fr_data->img = mlx_new_image(fr_data->mlx, fr_data->img_width, fr_data->img_height);
			if (!fr_data->img || (mlx_image_to_window(fr_data->mlx, fr_data->img, 0, 0) < 0))
				ft_error();
			ft_julia(fr_data);
		}
		mlx_key_hook(fr_data->mlx, &my_keyhook, NULL);
		mlx_scroll_hook(fr_data->mlx, &my_scrollhook, NULL);
		mlx_loop(fr_data->mlx);
		mlx_terminate(fr_data->mlx);
		return (EXIT_SUCCESS);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/12 12:40:56 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
		t_fr_data *fr_data;
		mlx_t *mlx;

	if (argc == 1)
	{
		printf(RED "Uh oh" WHT ", something is missing!\n" WHT);
		printf(GRN "Usage :" WHT " ./fractol " RED "[fractal_set_name]\n\n");
		printf(YEL "\tAvailable Sets\n");
		printf("\t--> [1] mandelbrot\n");
		printf("\t--> [2] julia\n");
		return (1);
	}
	else
	{
		// This line is for setting the window in maximised state
		//mlx_set_setting(MLX_MAXIMIZED, true);
		fr_data = get_data();
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
	/*
	if (argv[1] == 2 || argv[1] == "2")
	{
		// julia
	}
	*/
	return (0);
}

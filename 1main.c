/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/27 14:49:14 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void exec(t_fr_data *data, char *title)
{
	data->img = mlx_new_image(data->mlx, data->img_width, data->img_height);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		ft_error();
	data->f(data);
}

void get_arg(int argc, char **argv, t_fr_data *data)
{
	if (argc == 1)
		print_usage();
	else if (argv[1][0] == '2' && argv[1][1] == '\0')
	{
		if (argc == 4)
		{
			// get_data(argv[1][0]);
			// data->c_re = my_atof(argv[2]);
			// data->c_im = my_atof(argv[3]);
			puts("Julia");
			// data->f = &ft_julia;
		}
		else
			arg_usage(0);
	}
	else if (argv[1][0] == '1' && argv[1][1] == '\0')
	{
		get_data(argv[1][0]);
		data->f = &ft_mandelbrot;
		//exec(data, "Mandelbrot Set");
	}
	else
		print_usage();
}

int	main(int argc, char **argv)
{
	t_fr_data	*data;
	
	// get_data(argv[1][0]);
	get_arg(argc, argv, data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!data->mlx)
		ft_error();
	data->img = mlx_new_image(data->mlx, data->img_width, data->img_height);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		ft_error();
	
	// mlx_key_hook(data->mlx, &my_keyhook, data);
	// mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	// // mlx_cursor_hook(data->mlx, &my_mouse_pos, data);
	// mlx_loop(data->mlx);
	// mlx_terminate(data->mlx);
	// return (EXIT_SUCCESS);

	return (0);
}

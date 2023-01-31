/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:50:26 by loulou            #+#    #+#             */
/*   Updated: 2023/01/30 22:50:27 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

/*
Fct that allocates the correct size of the struc, then sets default 
parameters (set_defaults) and sets parameters depending on
the input (get_arg).
*/
t_fractol	*frctl_init(int argc, char *argv[])
{
	t_fractol	*frctl;

	frctl = (t_fractol *)malloc(sizeof(t_fractol));
	if (!frctl)
		return (NULL);
	frctl->color_scheme = malloc((5000 + 1) * sizeof(int));
	if (!(frctl->color_scheme))
		return (NULL);
	// 	fractol_free_kill_all(frctl);
	frctl->color_shift = 0;
	// sets default values
	set_defaults(frctl);
	//set which sets to display
	get_arg(argc, argv, frctl); 
	// return modified struct
	return (frctl);
}

/*
Fct that sets the default parmaters req'd
*/
int	set_defaults(t_fractol *frctl)
{
	t_complex *z;
	
	frctl->max_iter = 50;
	complex_set(&frctl->c_min, -2.0, -2.0);
	frctl->c_max.im = 2;
	frctl->c_max.re = (WIDTH / HEIGHT
			* (frctl->c_max.im - frctl->c_min.im)
			+ frctl->c_min.re);
	complex_set(&frctl->c_julia, -0.6, 0.6); 
	set_color_array(frctl);
	return (0);
}

void get_arg(int argc, char **argv, t_fractol *frctl)
{
	// frctl->frctl_fct = NULL;
	if (argc == 1)
		print_usage();
	if (argv[1][0] == '2' && argv[1][1] == '\0')
	{
		frctl->frctl_fct = ft_julia;
		if (argc == 4)
		{
			frctl->c_julia.re = my_atof(argv[2]);
			frctl->c_julia.im = my_atof(argv[3]);		
		}
		else
			arg_usage(0); //to modify
	}
	else if (argv[1][0] == '1' && argv[1][1] == '\0')
		frctl->frctl_fct = ft_mandelbrot;
		// puts("mandelbrot");
	else
		print_usage();
}

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	setup_mlx(t_fractol *frctl)
{	
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!frctl->mlx)
		ft_error();
	frctl->img = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	if (!frctl->img || (mlx_image_to_window(frctl->mlx, frctl->img, 0, 0) < 0))
		ft_error();
}
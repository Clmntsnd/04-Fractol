/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 14:10:29 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** Fractal's math functions 
*/
void	fract_calc(t_fractol *frctl)
{
	if (frctl->iter_max < 0)
		frctl->iter_max = 0;
	if (frctl->frctl_fct == 1)
		mandelbrot_pthread(frctl);
	else if (frctl->frctl_fct == 2)
		julia_pthread(frctl);
	else if (frctl->frctl_fct == 3)
		burningship_pthread(frctl);
}

/*
** Initiate default values req'd for each sets
*/
void	fract_init(t_fractol *frctl, char **argv)
{
	if (frctl->frctl_fct == 1)
		mandelbrot_init(frctl);
	else if (frctl->frctl_fct == 2)
		julia_init(frctl, argv);
	else if (frctl->frctl_fct == 3)
		burningship_init(frctl);
	fract_calc(frctl);
}

/*
** Initiate mlx and img, then send a message if something didn't work
*/
void	mlx_setup(t_fractol *frctl)
{
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	frctl->img = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	if (!frctl->mlx || !frctl->img
		|| (mlx_image_to_window(frctl->mlx, frctl->img, 0, 0) < 0))
	{	
		printf("Something went wrong during mlx or img initialization");
		exit(1);
	}
}

/*
** Attributes a number per sets per received args
*/
int	fract_sets(int argc, char **argv, t_fractol *frctl)
{
	if (argv[1][0] == '2')
	{
		if (argc < 4)
		{
			arg_usage(0);
			exit(0);
		}
		else
			frctl->frctl_fct = 2;
	}
	else if (argv[1][0] == '1')
		frctl->frctl_fct = 1;
	else if (argv[1][0] == '3')
		frctl->frctl_fct = 3;
	else
		print_usage();
	return (1);
}

/*
** Main function
*/
int	main(int argc, char *argv[])
{
	t_fractol	*frctl;

	if (argc == 1 || argv[1][1] != '\0')
		print_usage();
	if (argc >= 2 && ft_isdigit(ft_atoi(&argv[1][0])) == 0
		&& argv[1][1] == '\0')
	{
		frctl = (t_fractol *)malloc(sizeof(t_fractol));
		if (!frctl)
			return (1);
		if (fract_sets(argc, argv, frctl) != 0)
		{
			mlx_setup(frctl);
			fract_init(frctl, argv);
			mlx_key_hook(frctl->mlx, &my_keyhook, frctl);
			mlx_scroll_hook(frctl->mlx, &my_scrollhook, frctl);
			mlx_loop(frctl->mlx);
			mlx_terminate(frctl->mlx);
			return (EXIT_SUCCESS);
		}
	}
	return (0);
}

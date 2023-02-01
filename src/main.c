/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 21:38:07 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	fract_calc(t_fractol *frctl)
{
	if (frctl->iter_max < 0)
		frctl->iter_max = 0;
	if (frctl->frctl_fct == 1)
		mandelbrot_pthread(frctl);
	else if (frctl->frctl_fct == 2)
		julia_pthread(frctl);
}

void	fract_init(t_fractol *frctl)
{
	if (frctl->frctl_fct == 1)
		mandelbrot_init(frctl);
	else if (frctl->frctl_fct == 2)
		julia_init(frctl);
	fract_calc(frctl);
}

static	void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	mlx_setup(t_fractol *frctl)
{
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!frctl->mlx)
		ft_error();
	frctl->img = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	if (!frctl->img || (mlx_image_to_window(frctl->mlx, frctl->img, 0, 0) < 0))
		ft_error();
}

int	fract_sets(char **argv, t_fractol *frctl)
{
	if (argv[1][0] == '1')
		frctl->frctl_fct = 1;
	else if (argv[1][0] == '2' && argv[1][1] == '\0')
		frctl->frctl_fct = 2;
	else
		print_usage();
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fractol	*frctl;

	if (argc == 1 || argv[1][1] != '\0')
		print_usage();
	if (argc == 2 && argv[1][1] == '\0')
	{
		frctl = (t_fractol *)malloc(sizeof(t_fractol));
		if (!frctl)
			exit(1);
		mlx_setup(frctl);
		if ((fract_sets(argv, frctl)) == 0)
			exit(1);
		fract_init(frctl);
		mlx_key_hook(frctl->mlx, &my_keyhook, frctl);
		mlx_scroll_hook(frctl->mlx, &my_scrollhook, frctl);
		mlx_loop(frctl->mlx);
		mlx_terminate(frctl->mlx);
		return (EXIT_SUCCESS);
	}
}
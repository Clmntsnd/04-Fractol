/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:41:08 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 14:52:47 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

/*
Fct that allocates the correct size of the struc, then sets default 
parameters (set_defaults) and sets parameters depending on
the input (get_arg).
*/
t_fractol	*frctl_init(int argc, char *argv[])
{
	t_fractol	*frctl;

	if (!(frctl = malloc(sizeof(t_fractol))))
		return (NULL);
	frctl->color_scheme = malloc((5000 + 1) * sizeof(int));
	// if (frctl->color_scheme == NULL)
	// 	fractol_free_kill_all(frctl);
	frctl->color_shift = 0;
	set_defaults(frctl);
	get_arg(argc, argv, frctl); 
	return (frctl); //retourne la struct modified
}

/*
Fct that sets the default parmaters req'd
*/
int	set_defaults(t_fractol *frctl)
{
	frctl->max_iter = 28;
	complex_set(&frctl->c_min, -2.0, -2.0);
	frctl->c_max.im = 2;
	frctl->c_max.re = (WIDTH / HEIGHT
			* (frctl->c_max.im - frctl->c_min.im)
			+ frctl->c_min.re);
	//complex_set(&frctl->c_julia, -0.6, 0.6); 
	set_color_array(frctl);
	return (0);
}

void get_arg(int argc, char **argv, t_fractol *frctl)
{
	frctl->frctl_fct = NULL;
	if (argc == 1)
		print_usage();
	else if (argv[1][0] == '2' && argv[1][1] == '\0')
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
	//ft_mandelbrot(frctl);
	//mlx_loop_hook(mlx, ft_hooks, mlx);
	mlx_key_hook(frctl->mlx, &my_keyhook, frctl);
	mlx_loop(frctl->mlx);
	mlx_terminate(frctl->mlx);
}

double my_atof(const char *str)
{
    int		i;
	int		sign;
    double 	result;
    double 	decimal;

	i = 0;
	sign = -1;
	result = 0.0;
	decimal = 1.0;
    // Check for a sign
    if (str[i] == '-') 
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
        i++;
    // Extract the integer part of the number
    while (str[i] >= '0' && str[i] <= '9') 
	{
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        i++;

    // Extract the decimal part of the number
    while (str[i] >= '0' && str[i] <= '9')
	{
        result = result * 10 + (str[i] - '0');
        decimal *= 10;
        i++;
    }
    // Return the final result
    return sign * result / decimal;
}

void arg_usage(int flag)
{
	if (flag == 0)
		printf("Missing two others args");
}
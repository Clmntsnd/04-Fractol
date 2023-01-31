/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:38:13 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 14:42:59 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define BLU "\x1B[34m"
# define WHT "\x1B[37m"
# define YEL "\x1B[33m"
# define WIDTH 750
# define HEIGHT 750
# define THREAD_WIDTH 5
# define THREAD_NUMBER 150

// typedef struct s_fractol	t_fractol;
// typedef void	(*t_funcptr)(t_fractol *frctl);

// Struct that stocks complex nbr
// typedef struct s_complex
// {
// 	double	re;
// 	double	im;
// }	t_complex;

// Struct that stocks req'd MLX ptr in ordeer to launch
// typedef struct	s_mlx 
// {
// 	mlx_image_t	*img;
// 	mlx_t 		*mlx;
// }				t_mlx;

// Struct principale
typedef struct s_fractol 
{
	// double		c;
	// double		c_julia;
	// double		c_max;
	// double		c_min;
	// double		scale;
	// size_t		iter;
	// size_t		max_iter;
	// uint8_t		color_shift;
	// int			*color_scheme;

	mlx_image_t	*img;
	mlx_t 		*mlx;
	int			color;
	int			*color_scheme;
	uint8_t		color_shift;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			frctl_fct;
	int			iter;
	int			iter_max;
	int			show_text;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}	t_fractol;

/*
**	Main Functions
*/
void	mlx_setup(t_fractol *frctl);
int		fract_sets(char **argv, t_fractol *frctl);
void	fract_init(t_fractol *frctl);
int		fract_sets(char **argv, t_fractol *frctl);

/*
**	Calcul Functions
*/
void	fract_calc(t_fractol *frctl);

void	mandelbrot_init(t_fractol *frctl);
void	mandelbrot_calc(t_fractol *frctl);
void	*mandelbrot(void *param);
void	mandelbrot_pthread(t_fractol *frctl);

int		mouse_julia(int x, int y, t_fractol *frctl);
void	julia_init(t_fractol *frctl);
void	julia_calc(t_fractol *frctl);
void	*julia(void *param);
void	julia_pthread(t_fractol *frctl);

/*
**	Color Functions
*/


/*
**	Hooks & related functions
*/
void	my_keyhook(mlx_key_data_t keydata, t_fractol *frctl);


/*
**	Print Functions
*/
void	print_usage (void);
void	print_help(void);

#endif
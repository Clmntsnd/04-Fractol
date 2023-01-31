/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:38:13 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 22:55:37 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define WHT "\x1B[37m"
#define YEL "\x1B[33m"
#define WIDTH 800
#define HEIGHT 640

typedef struct s_fractol	t_fractol;
typedef void	(*t_funcptr)(t_fractol *frctl);

// Struct that stocks complex nbr
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

// Struct that stocks req'd MLX ptr in ordeer to launch
// typedef struct	s_mlx 
// {
// 	mlx_image_t	*img;
// 	mlx_t 		*mlx;
// }				t_mlx;

// Struct principale

typedef struct s_fractol 
{
	t_complex	c;
	t_complex	c_julia;
	t_complex	c_max;
	t_complex	c_min;
	t_complex	scale;
	size_t		iter;
	size_t		max_iter;
	t_funcptr	frctl_fct;
	mlx_image_t	*img;
	mlx_t 		*mlx;
	uint8_t		color_shift;
	int			*color_scheme;
	//bool		is_fixed;
}	t_fractol;

/*
**	Main Functions
*/
// int			fractol(int argc, char *argv[]);
t_fractol	*frctl_init(int argc, char *argv[]);
int			set_defaults(t_fractol *frctl);
void 		get_arg(int argc, char **argv, t_fractol *frctl);
void		fractol_loop(t_fractol *frctl);
void		setup_mlx(t_fractol *frctl);

/*
**	Calcul Functions
*/
void		complex_set(t_complex *z, double re, double im);
void		ft_julia(t_fractol *frctl);
void		ft_mandelbrot(t_fractol *frctl);

/*
**	Color Functions
*/
int			calc_color(t_fractol *frctl, size_t i);
int			get_color(t_fractol *frctl);
void		set_color_array(t_fractol *frctl);

/*
**	Hooks
*/
void		my_keyhook(mlx_key_data_t keydata, t_fractol *frctl);
void		move(keys_t key, t_fractol *frctl);
void		change_maxiter(keys_t key, t_fractol *frctl);

/*
**	Print Functions
*/
void		print_usage(void);
void		print_help(void);
double 		my_atof(const char *str);
void 		arg_usage (int flag);

#endif
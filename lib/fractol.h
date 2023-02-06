/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:38:13 by csenand           #+#    #+#             */
/*   Updated: 2023/02/02 20:14:16 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define BLU "\x1B[34m"
# define WHT "\x1B[37m"
# define YEL "\x1B[33m"
# define BLINK "\x1B[5m"
# define WIDTH 800
# define HEIGHT 720
# define THREAD_WIDTH 5
# define THREAD_NUMBER 144

// Struct principale
typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			x;
	int			y;
	int			y_max;
	int			frctl_fct;
	int			iter;
	int			iter_max;
	double		zoom;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		new_r;
	double		new_i;
	double		tmp;
	double		n;
}	t_fractol;

/*
**	Main Functions
*/
void		mlx_setup(t_fractol *frctl);
int			fract_sets(int argc, char **argv, t_fractol *frctl);
void		fract_init(t_fractol *frctl, char **argv);

/*
**	Calcul Functions
*/
void		fract_calc(t_fractol *frctl);

void		mandelbrot_init(t_fractol *frctl);
void		mandelbrot_calc(t_fractol *frctl);
void		*mandelbrot(void *param);
void		mandelbrot_pthread(t_fractol *frctl);

// int			mouse_julia(int x, int y, t_fractol *frctl);
void		julia_init(t_fractol *frctl, char **argv);
void		julia_calc(t_fractol *frctl);
void		*julia(void *param);
void		julia_pthread(t_fractol *frctl);

void		burningship_init(t_fractol *frctl);
void		burningship_calc(t_fractol *frctl);
void		*burningship(void *param);
void		burningship_pthread(t_fractol *frctl);

/*
**	Color Functions
*/
// uint32_t	set_color(int iter);
uint32_t	set_color(int iter, t_fractol *frctl);
int			get_rgba(int r, int g, int b, int a);

/*
**	Hooks & related functions
*/
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		change_maxiter(keys_t key, t_fractol *frctl);
void		move(keys_t key, t_fractol *frctl);
void		my_mouse_pos(double xpos, double ypos, void *param);

/*
** Utils Functions
*/
void		print_usage(void);
void		print_help(void);
void		arg_usage(int flag);
double		my_atof(const char *str);

#endif
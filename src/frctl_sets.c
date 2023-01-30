/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctl_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:31:14 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 13:30:52 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	ft_mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = pow(z.re, 2.0);
	tmp.im = pow(z.im, 2.0);
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = pow(z.re, 2.0);
		tmp.im = pow(z.im, 2.0);
		frctl->iter++;
	}
}

void	ft_julia(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = pow(z.re, 2.0);
	tmp.im = pow(z.im, 2.0);
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c_julia.im;
		z.re = tmp.re - tmp.im + frctl->c_julia.re;
		tmp.re = pow(z.re, 2.0);
		tmp.im = pow(z.im, 2.0);
		frctl->iter++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:55:07 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 10:17:15 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	ft_mandelbrot(t_data *data)
{
	double	xdelta;
	double	ydelta;

	xdelta = data->xmax - data->xmin;
	ydelta = data->ymax - data->ymin;

	data->i = 0;
	while (++(data->i) < WIDTH)
	{
		data->j = 0;
		while (++(data->j) < HEIGHT)
		{
            data->c_re = data->xmin + data->i * xdelta / WIDTH;
            data->c_im = data->ymin + data->j * ydelta / HEIGHT;
            data->zx = 0;
            data->zy = 0;
			data->iter = 0;
            while (pow(data->zx, 2) + pow(data->zy, 2) < 4 && data->iter < data->max_iter)
            {
                data->new_re = pow(data->zx, 2) - pow(data->zy, 2) + data->c_re;
				data->new_im = 2 * data->zx * data->zy + data->c_im;
                data->zx = data->new_re;
                data->zy = data->new_im;
				data->iter++;
			}
			mlx_put_pixel(data->img, data->i, data->j, set_color(data->iter));
		}
	}
}

/*
void	mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}
*/
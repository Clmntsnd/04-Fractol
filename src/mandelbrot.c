/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:59:57 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 20:21:38 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
#include <string.h>

void	mandelbrot_init(t_fractol *frctl)
{
	frctl->iter_max = 50;
	frctl->zoom = 300;
	frctl->xmin = -2;
	frctl->xmax = 1.2;
	frctl->ymin = -1.2;
	frctl->ymax = 1.2;
}

void	mandelbrot_calc(t_fractol *frctl)
{
	frctl->z_r = 0;
	frctl->z_i = 0;
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 4
		&& frctl->iter < frctl->iter_max)
	{
		frctl->new_re = pow(frctl->z_r, 2) - pow(frctl->z_i, 2) + frctl->c_r;
		frctl->new_im = 2 * frctl->z_i * frctl->z_r + frctl->c_i;
		frctl->z_r = frctl->new_re;
		frctl->z_i = frctl->new_im;
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0xFF);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, set_color(frctl->iter));
}

void	*mandelbrot(void *param)
{
	t_fractol	*frctl;
	int			tmp;
	double		xdelta;
	double		ydelta;

	frctl = (t_fractol *)param;
	xdelta = frctl->xmax - frctl->xmin;
	ydelta = frctl->ymax - frctl->ymin;
	tmp = frctl->y;
	frctl->x = 0;
	while (frctl->x < WIDTH)
	{
		frctl->y = tmp;
		while (frctl->y < frctl->y_max)
		{
			frctl->c_r = frctl->xmin + frctl->x * xdelta / WIDTH;
			frctl->c_i = frctl->ymin + frctl->y * ydelta / HEIGHT;
			mandelbrot_calc(frctl);
			frctl->y++;
		}
		frctl->x++;
	}
	return (param);
}

void	mandelbrot_pthread(t_fractol *frctl)
{
	t_fractol	param[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		// ATTENTION use my version of memcpy
		memcpy((void *)&param[i], (void *)frctl, sizeof(t_fractol));
		param[i].y = THREAD_WIDTH * i;
		param[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &param[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}

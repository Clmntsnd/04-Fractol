/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:26:14 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 20:00:48 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
#include <string.h>

int	mouse_julia(int x, int y, t_fractol *frctl)
{
	if (frctl->frctl_fct == 1 && frctl->julia_mouse == 1)
	{
		frctl->c_r = x * 2;
		frctl->c_i = y * 2 - 800;
		fract_calc(frctl);
	}
	return (0);
}

void	julia_init(t_fractol *frctl)
{
	frctl->iter_max = 28;
	frctl->zoom = 200;
	frctl->xmin = -1.5;
	frctl->xmax = 1.5;
	frctl->ymin = -1.5;
	frctl->ymax = 1.5;
	frctl->c_r = -0.70176;
	frctl->c_i = 0.3842;
	frctl->julia_mouse = 1;
}

void	julia_calc(t_fractol *frctl)
{
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

void	*julia(void *param)
{
	t_fractol	*frctl;
	int			tmp;
	double		xdelta;
	double		ydelta;

	frctl = (t_fractol *)param;
	xdelta = frctl->xmax - frctl->xmin;
	ydelta = frctl->ymax - frctl->ymin;
	frctl->x = 0;
	tmp = frctl->y;
	while (frctl->x < WIDTH)
	{
		frctl->y = tmp;
		while (frctl->y < frctl->y_max)
		{
			frctl->z_r = frctl->xmin + frctl->x * xdelta / WIDTH;
			frctl->z_i = frctl->ymin + frctl->y * ydelta / HEIGHT;
			julia_calc(frctl);
			frctl->y++;
		}
		frctl->x++;
	}
	return (param);
}

void	julia_pthread(t_fractol *frctl)
{
	t_fractol	param[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		memcpy((void *)&param[i], (void *)frctl,
			sizeof(t_fractol));
		param[i].y = THREAD_WIDTH * i;
		param[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &param[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}

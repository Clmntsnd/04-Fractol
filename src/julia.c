/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:26:14 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 16:21:52 by csenand          ###   ########.fr       */
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
	frctl->iter_max = 50;
	frctl->zoom = 200;
	frctl->x1 = -2.0;
	frctl->y1 = -1.9;
	frctl->color = 500;
	frctl->c_r = 0.285;
	frctl->c_i = 0.01;
	frctl->julia_mouse = 1;
}

void	julia_calc(t_fractol *frctl)
{
	frctl->z_r = frctl->x / frctl->zoom + frctl->x1;
	frctl->z_i = frctl->y / frctl->zoom + frctl->y1;
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 4 
		&& frctl->iter < frctl->iter_max)
	{
		frctl->tmp = frctl->z_r;
		frctl->z_r = pow(frctl->z_r, 2) - pow(frctl->z_i, 2) - 0.8
			+ (frctl->c_r / WIDTH);
		frctl->z_i = 2 * frctl->z_i * frctl->tmp + (frctl->c_i / WIDTH);
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0x000000);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y,
			(frctl->color * frctl->iter));
}

void	*julia(void *param)
{
	t_fractol	*frctl;
	int			tmp;

	frctl = (t_fractol *)param;
	frctl->x = 0;
	tmp = frctl->y;
	while (frctl->x < WIDTH)
	{
		frctl->y = tmp;
		while (frctl->y < frctl->y_max)
		{
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

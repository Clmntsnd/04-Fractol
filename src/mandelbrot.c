/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:59:57 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 14:51:29 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
#include <string.h>

void	mandelbrot_init(t_fractol *frctl)
{
	frctl->iter_max = 50;
	frctl->zoom = 300;
	frctl->x1 = -2.05;
	frctl->y1 = -1.3;
	frctl->color = 255;
}

void	mandelbrot_calc(t_fractol *frctl)
{
	frctl->c_r = frctl->x / frctl->zoom + frctl->x1;
	frctl->c_i = frctl->y / frctl->zoom + frctl->y1;
	frctl->z_r = 0;
	frctl->z_i = 0;
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 4 
			&& frctl->iter < frctl->iter_max)
	{
		frctl->tmp = frctl->z_r;
		frctl->z_r = pow(frctl->z_r, 2) -
			pow(frctl->z_i, 2) + frctl->c_r;
		frctl->z_i = 2 * frctl->z_i * frctl->tmp + frctl->c_i;
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0x000000);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, (frctl->color * frctl->iter));
}

void	*mandelbrot(void *param)
{
	t_fractol	*frctl;
	int		tmp;

	frctl = (t_fractol *)param;
	frctl->x = 0;
	tmp = frctl->y;
	while (frctl->x < WIDTH)
	{
		frctl->y = tmp;
		while (frctl->y < frctl->y_max)
		{
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
		memcpy((void*)&param[i], (void*)frctl, sizeof(t_fractol));
		param[i].y = THREAD_WIDTH * i;
		param[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &param[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}
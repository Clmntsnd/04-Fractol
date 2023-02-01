/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:26:14 by csenand           #+#    #+#             */
/*   Updated: 2023/02/01 17:59:28 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
//ATTENTION replace memcpy by ft_memcpy
#include <string.h>

void	julia_multi_init(t_fractol *frctl)
{
	frctl->iter_max = 28;
	frctl->zoom = 200;
	frctl->xmin = -2;
	frctl->xmax = 2;
	frctl->ymin = -2;
	frctl->ymax = 2;
	frctl->c_r = -0.8;
	frctl->c_i = 0.156;
	frctl->n = 10.0;
}

void	julia_multi_calc(t_fractol *frctl)
{
	
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 20 
		&& frctl->iter < frctl->iter_max)
	{
		frctl->new_r = pow((pow(frctl->z_r, 2) + pow(frctl->z_i, 2)), (frctl->n / 2)) * cos(frctl->n * atan2(frctl->z_i, frctl->z_r)) + frctl->c_r;
		frctl->new_i = pow((pow(frctl->z_r, 2) + pow(frctl->z_i, 2)), (frctl->n / 2)) * sin(frctl->n * atan2(frctl->z_i, frctl->z_r)) + frctl->c_i;	
		frctl->z_r = frctl->new_r;
		frctl->z_i = frctl->new_i;
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0xFF);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, set_color(frctl->iter));
}
  
void	*julia_multi(void *param)
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
			julia_multi_calc(frctl);
			frctl->y++;
		}
		frctl->x++;
	}
	return (param);
}

void	julia_multi_pthread(t_fractol *frctl)
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
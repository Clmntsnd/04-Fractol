/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:30:58 by csenand           #+#    #+#             */
/*   Updated: 2023/02/01 17:57:35 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
//ATTENTION replace memcpy by ft_memcpy
#include <string.h>

void	buddhabrot_init(t_fractol *frctl)
{
	frctl->iter_max = 20;
	frctl->zoom = 300;
	frctl->xmin = -2;
	frctl->xmax = 1.2;
	frctl->ymin = -1.2;
	frctl->ymax = 1.2;
	frctl->c_r = -0.8;
	frctl->c_i = 0.156;
}

void	buddhabrot_calc(t_fractol *frctl)
{
	frctl->iter = 0;
	while (frctl->iter < frctl->iter_max) 
	{
		if (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) > 4.0)
			break;
		frctl->new_r = pow(frctl->z_r, 2) - pow(frctl->z_i, 2) + frctl->c_r;
		frctl->new_i = 2 * frctl->z_i * frctl->z_r + frctl->c_i;
		frctl->z_r = frctl->new_r;
		frctl->z_i = frctl->new_i;
		frctl->iter++;
		// frctl->x = frctl->iter;
		// frctl->y = frctl->iter;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0xFF);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, set_color(frctl->iter));
}

void 	*buddhabrot(void *param) 
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
			frctl->z_r = frctl->x * 4.0 / WIDTH - 2.0;
  			frctl->z_i = frctl->y * 4.0 / HEIGHT - 2.0;
			buddhabrot_calc(frctl);
			// if (p.x < ITER_MAX)
			// 	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			frctl->y++;
		}
		frctl->x++;
	}
	return (param);
}

void	buddhabrot_pthread(t_fractol *frctl)
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
		pthread_create(&t[i], NULL, buddhabrot, &param[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}
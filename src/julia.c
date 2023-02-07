/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:26:14 by csenand           #+#    #+#             */
/*   Updated: 2023/02/06 22:40:46 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	if (!src || !dst)
		return (dst);
	c_dst = (char *) dst;
	c_src = (char *) src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (c_dst);
}

void	julia_init(t_fractol *frctl, char **argv)
{
	frctl->iter_max = 28;
	frctl->zoom = 300;
	frctl->xmin = -1.5;
	frctl->xmax = 1.5;
	frctl->ymin = -1.5;
	frctl->ymax = 1.5;
	frctl->c_r = my_atof(argv[2]);
	frctl->c_i = my_atof(argv[3]);
}

void	julia_calc(t_fractol *frctl)
{
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 4
		&& frctl->iter < frctl->iter_max)
	{
		frctl->new_r = pow(frctl->z_r, 2) - pow(frctl->z_i, 2) + frctl->c_r;
		frctl->new_i = 2 * frctl->z_i * frctl->z_r + frctl->c_i;
		frctl->z_r = frctl->new_r;
		frctl->z_i = frctl->new_i;
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0xFF);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y,
			set_color(frctl->iter, frctl));
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
		ft_memcpy((void *)&param[i], (void *)frctl,
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

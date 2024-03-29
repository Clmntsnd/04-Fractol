/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:54:49 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 14:10:21 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../include/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	set_color(int iter, t_fractol	*frctl)
{
	int			r;
	int			g;
	int			b;
	double		t;

	t = (double)iter / (double)frctl->iter_max;
	if (frctl->frctl_color == 1)
	{
		r = (int)(9 * (1 - t) * pow(t, 3) * 255);
		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (frctl->frctl_color == 2)
	{
		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		r = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (frctl->frctl_color == 3)
	{
		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
		r = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		g = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (get_rgba(r, g, b, 255));
}
	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:54:49 by csenand           #+#    #+#             */
/*   Updated: 2023/02/02 20:18:06 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// uint32_t	set_color(int iter)
// {	
// 	uint32_t	gray_level;

// 	gray_level = 255 * (iter % 2);
// 	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));
// }

// uint32_t	set_color(int iter)
// {
//   	int red = 0;
//   	int green = 0;
// 	int blue = 0;

// 	if (iter < 64)
// 	{
// 		red = iter * 2;
// 		green = iter * 4;
// 		blue = iter * 8;
// 	}
// 	else if (iter < 128)
// 	{
// 		red = 255;
// 		green = (iter - 64) * 2;
// 		blue = 0;
// 	}
// 	else
// 	{
// 		red = 255;
// 		green = 255;
// 		blue = (iter - 128) * 4;
// 	}
// 	return (get_rgba(red, green, blue, 255));
// }

uint32_t	set_color(int iter, t_fractol	*frctl)
{
	int			r;
	int			g;
	int			b;
	double		t;

	t = (double)iter / (double)frctl->iter_max;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (get_rgba(r, g, b, 255));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:59:12 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 14:03:05 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

int	calc_color(t_fractol *frctl, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];
	double	div;

	cs = frctl->color_shift;
	div = (double)i / frctl->max_iter;
	if (frctl->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - div), 3) * div * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * pow(div, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_color(t_fractol *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

void	set_color_array(t_fractol *frctl)
{
	size_t	i;

	i = 0;
	while (i <= frctl->max_iter)
	{
		frctl->color_scheme[i] = calc_color(frctl, i);
		i++;
	}
}


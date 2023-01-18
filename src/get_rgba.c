/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:54:49 by csenand           #+#    #+#             */
/*   Updated: 2023/01/18 10:27:06 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t set_color(int c)
{	
	t_fr_data *fr_data;
	double	fraction;
	int		red;
	int		green;
	int		blue;
/*
	fraction = c / fr_data->max_iter;
	if (fr_data->iter  == fr_data->max_iter)
		return (get_rgba(0x0, 0x0, 0x0, 0xFF));
	if (fraction < 0.5)
	{
		red = (255 * (2 * fraction));
		green = 0;
		blue = (255 * (1 - 2 * fraction));
	}
	else
	{
		green = (255 * (1 - 2 * fraction));
		red = (255 * (2 * fraction - 1));
		blue = 0;
	}
	return (get_rgba(red, green, blue, 255));
*/

	uint32_t	gray_level;

	gray_level = 255 * (c % 2);
	return (get_rgba(gray_level, gray_level, gray_level, 0xFF));

/*
		int color;

		color = 0;
		if (c < 50)
			color = get_rgba(215,31,31,255); //red
		else if (c >= 65 && c <=75)
			color = get_rgba(255, 0, 255, 255);
		else
			color = get_rgba(0,0,0,255); //black
	return (color);
*/
	
}
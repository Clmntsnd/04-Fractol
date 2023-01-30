/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:54:49 by csenand           #+#    #+#             */
/*   Updated: 2023/01/20 14:03:45 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t set_color(int iter)
{	
/*
	t_fr_data *fr_data;
	double	fraction;
	int		red;
	int		green;
	int		blue;
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

	// uint32_t	gray_level;

	// gray_level = 255 * (iter % 2);
	// return (get_rgba(gray_level, gray_level, gray_level, 0xFF));

	t_fr_data* fr_data;
	int color = 0;
    if (iter == fr_data->max_iter)
        color = get_rgba(0,0,0,255); // black
    else
	{
        // Use the iteration count to determine the color
        int red = (iter * 15) % 255;
        int green = (iter * 7) % 255;
        int blue = (iter * 3) % 255;
       	color = get_rgba(red, green, blue, 255);
    }
    return color;

/*
	int color;

	color = 0;
	if (c < 50)
		color = get_rgba(215,31,31,255); //red
	else if (c >= 50 && c <=100)
		color = get_rgba(255, 0, 255, 255);
	else
		color = get_rgba(0,0,0,255); //black
	return (color);
*/
}

// uint32_t set_color(int iter) 
// {
// 	t_fr_data* fr_data;
// 	//uint32_t frequency;
// 	uint32_t red;
// 	uint32_t green;
// 	uint32_t blue;
	
//     int color = 0;
//     if (iter == fr_data->max_iter)
//         color = get_rgba(0,0,0,255); // black
//     else
// 	{
//         //frequency = 0.3;
//         red   = sin(iter + 0) * 127 + 128;
//         green = sin(iter + 2) * 127 + 128;
//         blue  = sin(iter + 4) * 127 + 128;
//         get_rgba(red, green, blue, 255);
//     }
//     return color;
// }
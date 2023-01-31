/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:18 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 16:12:35 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, t_fractol *frctl)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	// else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	// 	move(keydata.key, frctl);
	// else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
	// 	move(keydata.key, frctl);
	// else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_O)
	// 	change_maxiter(keydata.key, frctl);
	else if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		print_help();
	// fract_calc(frctl);
}

// void	move(keys_t key, t_fractol *frctl)
// {
// 	c_size.re = frctl->c_max.re - frctl->c_min.re;
// 	c_size.im = frctl->c_max.im - frctl->c_min.im;
// 	if (key == MLX_KEY_UP)
// 	{
// 		frctl->c_min.im += c_size.im * 0.05;
// 		frctl->c_max.im += c_size.im * 0.05;
// 	}
// 	else if (key == MLX_KEY_DOWN)
// 	{
// 		frctl->c_min.im -= c_size.im * 0.05;
// 		frctl->c_max.im -= c_size.im * 0.05;
// 	}
// 	else if (key == MLX_KEY_LEFT)
// 	{
// 		frctl->c_min.re -= c_size.re * 0.05;
// 		frctl->c_max.re -= c_size.re * 0.05;
// 	}
// 	else if (key == MLX_KEY_RIGHT)
// 	{
// 		frctl->c_min.re += c_size.re * 0.05;
// 		frctl->c_max.re += c_size.re * 0.05;
// 	}
// }

// void	change_maxiter(keys_t key, t_fractol *frctl)
// {
// 	if (key == MLX_KEY_I)
// 	{
// 		if (frctl->iter_max == 5000)
// 			return ;
// 		else if (frctl->iter_max < 50)
// 			frctl->iter_max += 1;
// 		else if (frctl->iter_max < 5000)
// 		{
// 			frctl->iter_max = (int)(frctl->iter_max * 1.05);
// 			if (frctl->iter_max > 5000)
// 				frctl->iter_max = 5000;
// 		}
// 	}
// 	else if (key == MLX_KEY_O)
// 	{
// 		if (frctl->iter_max > 50)
// 			frctl->iter_max = frctl->iter_max * 0.95;
// 		else if (frctl->iter_max > 1)
// 			frctl->iter_max -= 1;
// 	}
// 	set_color_array(frctl);
// }
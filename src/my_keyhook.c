/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:18 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 14:10:41 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)param;
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_LEFT))
		move(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_I)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_O))
		change_maxiter(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_R)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_G)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_B))
		color_shift(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_H))
		print_help();
}

void	move(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_UP)
	{	
		frctl->ymin += 15 / frctl->zoom;
		frctl->ymax += 15 / frctl->zoom;
	}
	if (key == MLX_KEY_DOWN)
	{	
		frctl->ymin -= 15 / frctl->zoom;
		frctl->ymax -= 15 / frctl->zoom;
	}
	if (key == MLX_KEY_LEFT)
	{	
		frctl->xmin += 15 / frctl->zoom;
		frctl->xmax += 15 / frctl->zoom;
	}
	if (key == MLX_KEY_RIGHT)
	{	
		frctl->xmin -= 15 / frctl->zoom;
		frctl->xmax -= 15 / frctl->zoom;
	}
	fract_calc(frctl);
}

void	change_maxiter(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_I)
	{
		if (frctl->iter_max == 5000)
			return ;
		else if (frctl->iter_max < 50)
			frctl->iter_max += 1;
		else if (frctl->iter_max < 5000)
		{
			frctl->iter_max = (int)(frctl->iter_max * 1.05);
			if (frctl->iter_max > 5000)
				frctl->iter_max = 5000;
		}
	}
	else if (key == MLX_KEY_O)
	{
		if (frctl->iter_max > 50)
			frctl->iter_max = frctl->iter_max * 0.95;
		else if (frctl->iter_max > 1)
			frctl->iter_max -= 1;
	}
	fract_calc(frctl);
}

void	color_shift(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_B)
		frctl->frctl_color = 1;
	if (key == MLX_KEY_R)
		frctl->frctl_color = 2;
	if (key == MLX_KEY_G)
		frctl->frctl_color = 3;
	fract_calc(frctl);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol			*frctl;

	frctl = (t_fractol *)param;
	if (xdelta == 0)
		;
	frctl->zoom = 300;
	if (ydelta > 0)
	{
		frctl->ymin *= 0.95;
		frctl->ymax *= 0.95;
		frctl->xmin *= 0.95;
		frctl->xmax *= 0.95;
		frctl->zoom *= 1.1;
	}
	frctl->zoom = 300;
	if (ydelta < 0)
	{
		frctl->ymin *= 1.12;
		frctl->ymax *= 1.12;
		frctl->xmin *= 1.12;
		frctl->xmax *= 1.12;
		frctl->zoom *= 0.8;
	}
	fract_calc(frctl);
}

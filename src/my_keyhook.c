/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:18 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 22:08:22 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol			*frctl;

	frctl = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		move(keydata.key, frctl);
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		move(keydata.key, frctl);
	else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_O)
		change_maxiter(keydata.key, frctl);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		fract_init(frctl);
	else if (keydata.key == MLX_KEY_Z && keydata.action == MLX_REPEAT)
		mlx_cursor_hook(frctl->mlx, &my_mouse_pos, frctl);
	else if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		print_help();
	fract_calc(frctl);
}

void	move(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_UP)
	{	
		frctl->ymin += 30 / frctl->zoom;
		frctl->ymax += 30 / frctl->zoom;
	}
	if (key == MLX_KEY_DOWN)
	{	
		frctl->ymin -= 30 / frctl->zoom;
		frctl->ymax -= 30 / frctl->zoom;
	}
	if (key == MLX_KEY_LEFT)
	{	
		frctl->xmin -= 30 / frctl->zoom;
		frctl->xmax -= 30 / frctl->zoom;
	}
	if (key == MLX_KEY_RIGHT)
	{	
		frctl->xmin += 30 / frctl->zoom;
		frctl->xmax += 30 / frctl->zoom;
	}
	fract_calc(frctl);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol			*frctl;

	frctl = (t_fractol *)param;
	if (xdelta == 0)
		printf("");
	if (ydelta > 0)
	{
		frctl->ymin *= 0.9;
		frctl->ymax *= 0.9;
		frctl->xmin *= 0.9;
		frctl->xmax *= 0.9;
	}	
	if (ydelta < 0)
	{
		frctl->ymin *= 1.1;
		frctl->ymax *= 1.1;
		frctl->xmin *= 1.1;
		frctl->xmax *= 1.1;
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

void	my_mouse_pos(double xpos, double ypos, void *param)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)param;
	frctl->c_r = xpos / WIDTH;
	frctl->c_i = ypos / HEIGHT;
	//printf("x : %f, y : %f\n", xpos, ypos);
	// frctl->c_r = (cos(xpos) + 1) * 2 - 2;
	// frctl->c_i = (cos(ypos) + 1) * 2 - 2;
}
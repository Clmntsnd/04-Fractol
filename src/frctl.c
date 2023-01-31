/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:03 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 21:10:37 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

/*
Fct that initiates the data req'd in order to calculate and manade MLX set up
*/
// int	fractol(int argc, char *argv[])
// {
// 	t_fractol	*frctl;
	
// 	//initiate all params req'd to calculate the set
// 	frctl = frctl_init(argc, argv);
// 	if (!frctl)
// 		return (-1);
// 	setup_mlx(frctl);
// 	fractol_loop(frctl);
// 	mlx_loop(frctl->mlx);
// 	mlx_terminate(frctl->mlx);
// 	return (EXIT_SUCCESS);
// }

void	fractol_loop(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

	frctl->scale.re = (frctl->c_max.re - frctl->c_min.re) / WIDTH;
	frctl->scale.im = (frctl->c_max.im - frctl->c_min.im) / HEIGHT;
	y = - 1;
	while (++y < HEIGHT)
	{
		frctl->c.im = frctl->c_max.im - y * frctl->scale.im;
		x = -1;
		while (++x < WIDTH)
		{
			frctl->c.re = frctl->c_min.re + x * frctl->scale.re;
			frctl->frctl_fct(frctl);
		}
		mlx_put_pixel(frctl->img, x, y, get_color(frctl));
	}
}
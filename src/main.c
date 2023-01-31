/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 21:10:30 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	main(int argc, char *argv[])
{
	//fractol(argc, argv);
	
	t_fractol	*frctl;
	
	frctl = frctl_init(argc, argv);
	if (!frctl)
		return (-1);
	setup_mlx(frctl);
	fractol_loop(frctl);
	mlx_loop(frctl->mlx);
	mlx_terminate(frctl->mlx);
	return (EXIT_SUCCESS);
	return (0);
}

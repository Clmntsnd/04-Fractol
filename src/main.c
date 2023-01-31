/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 22:57:38 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	main(int argc, char *argv[])
{
	//fractol(argc, argv);
	
	t_fractol	*frctl;
	//initiate 'frctl' that contains all params 
	frctl = frctl_init(argc, argv);
	if (!frctl)
		return (-1);
	setup_mlx(frctl);
	fractol_loop(frctl);
	mlx_key_hook(frctl->mlx, &my_keyhook, frctl);
	mlx_loop(frctl->mlx);
	mlx_terminate(frctl->mlx);
	return (EXIT_SUCCESS);
}

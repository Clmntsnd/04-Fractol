/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:59 by csenand           #+#    #+#             */
/*   Updated: 2023/01/10 13:44:07 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define RED	"\x1B[31m"
#define GRN	"\x1B[32m"
#define WHT	"\x1B[37m"
#define YEL	"\x1B[33m"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf(RED"Uh oh"WHT", something is missing!\n"WHT);
		printf(GRN"Usage :"WHT" ./fractol "RED"[fractal_set_name]\n\n");
		printf(YEL"\tAvailable Sets\n");
		printf("\t--> [1] mandelbrot\n");
		printf("\t--> [2] julia\n");
		return (1);
	}
	if (argv[1] == 1 || argv[1] == "1" )
	{
		// mandelbrot
	}
	if (argv[1] == 2 || argv[1] == "2" )
	{
		// julia
	}
	return (0);
}
 
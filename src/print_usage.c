/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:45:33 by csenand           #+#    #+#             */
/*   Updated: 2023/01/31 22:35:28 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	print_usage(void)
{
	printf(RED "\n❌ Uh oh" WHT ", something went wrong! See Below.\n\n" WHT);
	printf(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n\n");
	printf(YEL "📝 Available Sets\n");
	printf("  --> 1️⃣  Mandelbrot\n");
	printf("  --> 2️⃣  Julia\n\n");
	printf("    |-> For Julia, please provide 2 args :\n");
	printf("    |-> ./fractol 2 [A] [B]\n");
	printf("    |-> A and B are floats nb (-2 < A < 2 & -2 < B < 2)\n\n");
	printf("    |-> Few examples that you could try\n");
	printf("    |-> ./fractol 2 0.285 0.01\n");
	printf("    |-> ./fractol 2 0.285 0\n");
	printf("    |-> ./fractol 2 -0.70176 0.3842\n");
	printf("    |-> ./fractol 2 0 -0.8\n\n");
	printf(GRN "Please type the accurate command to start the program\n");
}

void	print_help(void)
{
	printf(YEL "\n Key Hooks (all sets)\n\n");
	printf(WHT "  esc		| Quit program\n");
	printf("  ⬆		| Move up\n");
	printf("  ⬇		| Move down\n");
	printf("  <->		| Move left|right\n");
	printf("  r		| reset to default parameters");
	printf("  h		| Show help\n");
	printf("  mouse wheel	| Zoom in and out\n");
	printf(YEL "\n Key Hooks (Julia set)\n\n");
	printf(WHT"  c + mouse mvt	| change values to show different sets\n");
}

void	arg_usage(int flag)
{
	if (flag == 0)
		printf("Missing two others args");
}
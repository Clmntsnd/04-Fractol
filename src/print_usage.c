/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:45:33 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 13:31:04 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void print_usage(void)
{
	printf(RED "\n❌ Uh oh" WHT ", something is missing! See Below.\n\n" WHT);
	printf(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n\n");
	printf(YEL "📝 Available Sets\n");
	printf("  --> 1️⃣  Mandelbrot\n");
	printf("  --> 2️⃣  Julia\n\n");
	printf("    |-> For Julia, please provide 2 args :\n");
	printf("    |-> ./fractol 2 [A] [B]\n");
	printf("    |-> A and B are floats nb (-2 < A < 2 & -2 < B < 2)\n\n");
	printf(GRN "Please type the accurate command to start the program\n");
}

void	print_help(void)
{
	printf(YEL "\n Key Hooks (all sets)\n");
	printf(WHT "  esc		| Quit program");
	printf("  ⬆		| Move up");
	printf("  ⬇		| Move down");
	printf("  <->		| Move left|right");
	printf("  r		| change colors to "RED"red"WHT);
	printf("  g		| change colors to "GRN"green"WHT);
	printf("  b		| change colors to "BLU"blue"WHT);
	printf("  h		| Show help");
	printf("  mouse wheel	| Zoom in and out");
	printf(YEL "\n Key Hooks (Julia set)\n");
	printf(WHT"  c + mouse mvt	| change values to show different sets");
}

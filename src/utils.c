/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:13:17 by loulou            #+#    #+#             */
/*   Updated: 2023/01/19 14:08:16 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

double my_atof(char *str)
{
    int		i;
	int		sign;
    double 	result;
    double 	decimal;

	i = 0;
	sign = -1;
	result = 0.0;
	decimal = 1.0;
    // Check for a sign
    if (str[i] == '-') 
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
        i++;
    // Extract the integer part of the number
    while (str[i] >= '0' && str[i] <= '9') 
	{
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        i++;

    // Extract the decimal part of the number
    while (str[i] >= '0' && str[i] <= '9')
	{
        result = result * 10 + (str[i] - '0');
        decimal *= 10;
        i++;
    }
    // Return the final result
    return sign * result / decimal;
}

int print_usage (void)
{
	printf(RED "\n❌ Uh oh" WHT ", something is missing! See Below.\n\n" WHT);
	printf(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n");
	printf(YEL "\n📝 Available Sets\n");
	printf("  --> 1️⃣  Mandelbrot\n");
	printf("  --> 2️⃣  Julia (*)\n\n");
	printf("(*) For Julia, please provide 2 args :\n");
	printf("\t|-> ./fractol 2 [A] [B]\n");
	printf("\t|-> A and B are floats nb (-2 < A < 2 & -2 < B < 2)\n");
	printf(GRN "\nPlease type the accurate command to start the program \n");
	return (1);
}
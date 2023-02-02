/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:45:33 by csenand           #+#    #+#             */
/*   Updated: 2023/02/02 16:15:48 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static int	check_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	return (sign);
}

double	my_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	if (!str)
		return (0);
	i = 0;
	result = 0.0;
	decimal = 1.0;
	if (str[i])
	{
		sign = check_sign(str);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	return (sign * result / decimal);
}

void	print_usage(void)
{
	printf(RED "\n❌ Uh oh" WHT ", something went wrong! See Below.\n\n" WHT);
	printf(GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n\n");
	printf(YEL "📝 Available Sets\n");
	printf("  --> 1️⃣  Mandelbrot\n");
	printf("  --> 2️⃣  Julia\n");
	printf("  --> 3️⃣  Burningship\n\n");
	printf("    |-> For Julia, please provide 2 args :\n");
	printf("    |-> ./fractol 2 [A] [B]\n\n");
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
	printf("  r		| reset to default parameters\n");
	printf("  h		| Show help\n");
	printf("  mouse wheel	| Zoom in and out\n");
	printf(YEL "\n Key Hooks (Julia set)\n\n");
	printf(WHT"  z + mouse mvt	| change values to show different sets\n");
}

void	arg_usage(int flag)
{
	if (flag == 0)
		printf("Missing two others args");
}

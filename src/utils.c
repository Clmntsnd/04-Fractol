/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:45:33 by csenand           #+#    #+#             */
/*   Updated: 2023/09/10 17:44:54 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	printf(RED "\n❌ Ooops" WHT ", something went wrong!\n\n" WHT
		GRN "✅ Usage :" WHT " ./fractol " RED "[fractal_set_nb]\n\n"
		YEL "📝 Available Sets\n\n"
		"   --> 1️⃣  Mandelbrot\n"
		"   --> 2️⃣  Julia\n"
		"   --> 3️⃣  Burningship\n\n"
		YEL"    |-> For Julia, please provide 2 arguments :\n" WHT
		"    |-> ./fractol 2 [A] [B]\n\n"
		YEL "    |-> Few examples that you could try\n" WHT
		"      |-> ./fractol 2 0.285 0.01\n"
		"      |-> ./fractol 2 0.285 0\n"
		"      |-> ./fractol 2 -0.70176 0.3842\n"
		"      |-> ./fractol 2 0 -0.8\n\n"
		YEL "🔔 When executing the program, you can press 'h',\n"
		"   it'll display a Key Hooks menu in the terminal\n"WHT);
	exit(0);
}

void	print_help(void)
{
	printf(YEL "\n Key Hooks (all sets)\n\n"
		WHT "  esc		| Quit program\n"
		"  ⬆		| Move up\n"
		"  ⬇		| Move down\n"
		"  <->		| Move left|right\n"
		"  r		| change colors to "RED"red\n"WHT
		"  g		| change colors to "GRN"green\n"WHT
		"  b		| change colors to "BLU"blue\n"WHT
		"  h		| Show help\n"
		"  mouse wheel	| Zoom in and out\n");
}

void	arg_usage(int flag)
{
	if (flag == 0)
	{
		printf(RED "\n❌ Wrong Usage\n\n"
			GRN "✅ Usage :" WHT " ./fractol 2 " RED "[A] [B]\n\n"
			YEL "    |-> Few examples that you could try\n" WHT
			"      |-> ./fractol 2 0.285 0.01\n"
			"      |-> ./fractol 2 0.285 0\n"
			"      |-> ./fractol 2 -0.70176 0.3842\n"
			"      |-> ./fractol 2 0 -0.8\n\n");
	}
}

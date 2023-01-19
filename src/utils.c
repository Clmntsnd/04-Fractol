/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:13:17 by loulou            #+#    #+#             */
/*   Updated: 2023/01/19 08:16:48 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

double my_atof(char* str)
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
    // Check for a decimal point
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

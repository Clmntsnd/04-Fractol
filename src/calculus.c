/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:56:43 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 13:30:47 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

/*
Fct that assign compex and reel part of the set into the struct 
*/
void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}
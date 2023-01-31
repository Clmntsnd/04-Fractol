/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:56:43 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 16:25:11 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

/*
Fct that assign compex and reel part of the set into the struct 
*/
void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}
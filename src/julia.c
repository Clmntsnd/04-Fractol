/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:28 by csenand           #+#    #+#             */
/*   Updated: 2023/01/18 15:08:45 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	ft_julia(t_fr_data *fr_data)
{
	double	xdelta;
	double	ydelta;

	xdelta = fr_data->xmax - fr_data->xmin;
	ydelta = fr_data->ymax - fr_data->ymin;
	
	// fr_data->c_re = - 0.70176;
	// fr_data->c_im = 0.3842;
	//0.285 + 0.01i
	//−0.70176 − 0.3842

	fr_data->i = -1;
	while (++(fr_data->i) < fr_data->img_width)
	{
		fr_data->j = -1;
		while (++(fr_data->j) < fr_data->img_height)
		{
			
			fr_data->zx = fr_data->xmin + fr_data->i * xdelta / fr_data->img_width;
            fr_data->zy = fr_data->ymin + fr_data->j * ydelta / fr_data->img_height;;
			fr_data->iter = 0;
            while (pow(fr_data->zx, 2) + pow(fr_data->zy, 2) < 4 && fr_data->iter < fr_data->max_iter)
            {
                fr_data->new_re = pow(fr_data->zx, 2) - pow(fr_data->zy, 2) + fr_data->c_re;
				fr_data->new_im = 2 * fr_data->zx * fr_data->zy + fr_data->c_im;
                fr_data->zx = fr_data->new_re;
                fr_data->zy = fr_data->new_im;
				fr_data->iter++;
			}
			mlx_put_pixel(fr_data->img, fr_data->i, fr_data->j, set_color(fr_data->iter));
		}
	}
}
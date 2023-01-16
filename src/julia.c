/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:28 by csenand           #+#    #+#             */
/*   Updated: 2023/01/16 17:07:32 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	ft_julia(t_fr_data *fr_data)
{
	fr_data->c_re = 0.285;
	fr_data->c_im = -0.01;
	//0.285 + 0.01i

	printf("xmin : %f\n", fr_data->xmin);
	printf("xmax : %f\n", fr_data->xmax);
	printf("ymin : %f\n", fr_data->ymin);
	printf("ymax : %f\n\n", fr_data->ymax);

	fr_data->i = 0;
	while (++(fr_data->i) < fr_data->img_width)
	{
		fr_data->j = 0;
		while (++(fr_data->j) < fr_data->img_height)
		{
            fr_data->zx = 0;
            fr_data->zy = 0;
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
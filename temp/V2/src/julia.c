/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:28 by csenand           #+#    #+#             */
/*   Updated: 2023/01/30 10:03:57 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"


/*
*/
void	ft_julia(t_data *data)
{
	double	xdelta;
	double	ydelta;

	xdelta = data->xmax - data->xmin;
	ydelta = data->ymax - data->ymin;
	
	// data->c_re = my_atof(arg1);
	// data->c_im = my_atof(arg2);
	// data->c_re = - 0.70176;
	// data->c_im = 0.3842;
	//0.285 + 0.01i
	//−0.70176 − 0.3842

	data->i = 0;
	while (++(data->i) < data->img_width)
	{
		data->j = 0;
		while (++(data->j) < data->img_height)
		{
			
			data->zx = data->xmin + data->i * xdelta / data->img_width;
            data->zy = data->ymin + data->j * ydelta / data->img_height;
			data->iter = 0;
            while (pow(data->zx, 2) + pow(data->zy, 2) < 4 && data->iter < data->max_iter)
            {
                data->new_re = pow(data->zx, 2) - pow(data->zy, 2) + data->c_re;
				data->new_im = 2 * data->zx * data->zy + data->c_im;
                data->zx = data->new_re;
                data->zy = data->new_im;
				data->iter++;
			}
			mlx_put_pixel(data->img, data->i, data->j, set_color(data->iter));
		}
	}
}

/*
//Struct to hold the parameters for the thread
typedef struct s_pixel_thread_params
{
    int xp;
    int yp;
    t_fr_data* fr_data;
}			t_pixel_thread_params;
*/

/*

// Function to be executed by the thread
void* calculate_pixel(void* arg) 
{
	t_fr_data		*fr_data;
	unsigned int	x;

	fr_data = (t_fr_data *)arg;
	fr_data->i = -1;
	while (++(fr_data->i) < fr_data->img_width)
	{
		fr_data->j = -1;
		while (++(fr_data->j) < fr_data->img_height)
		{
			fr_data->zx = fr_data->xmin + fr_data->i * fr_data->xdelta / fr_data->img_width;
            fr_data->zy = fr_data->ymin + fr_data->j * fr_data->ydelta / fr_data->img_height;
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
	return (NULL);
}

void ft_julia(t_fr_data *fr_data)
{
	//Create a thread array to hold all the threads
	unsigned int	y;
	unsigned int	i;
	pthread_t 	threads[fr_data->img_height * fr_data->img_width];
	int 		thread_count;

	t_fr_data	thread_params[fr_data->img_height * fr_data->img_width];
	thread_count = 0;
	// Iterate over the width and height of the image
	while (thread_count < fr_data->img_height * fr_data->img_width)
	{
		thread_params[thread_count] = *fr_data;
		thread_params[thread_count].yp = thread_count;
		// Set the parameters for the thread
		// t_fr_data thread_params = {i, j, fr_data};
		// Create the thread and pass it the parameters
		pthread_create(&threads[thread_count], NULL, calculate_pixel, &thread_params[thread_count]);
		thread_count++;
	}
	i = -1;
	// Wait for all the threads to finish executing
	while (++i < fr_data->img_height)
		pthread_join(threads[i], NULL);
}*/
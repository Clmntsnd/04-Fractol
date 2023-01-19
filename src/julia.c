/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:28 by csenand           #+#    #+#             */
/*   Updated: 2023/01/19 16:00:25 by csenand          ###   ########.fr       */
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
	
	// fr_data->c_re = my_atof(arg1);
	// fr_data->c_im = my_atof(arg2);
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
/*

// Struct to hold the parameters for the thread
// typedef struct s_pixel_thread_params
// {
//     int xp;
//     int yp;
//     t_fr_data* fr_data;
// }			t_pixel_thread_params;

// Function to be executed by the thread
void* calculate_pixel(void* arg) 
{
    t_pixel_thread_params* params = (t_pixel_thread_params*) arg;
    int x = params->x;
    int y = params->y;
    t_fr_data* fr_data = params->fr_data;
	double xdelta;
	double ydelta;
	xdelta = fr_data->xmax - fr_data->xmin;
	ydelta = fr_data->ymax - fr_data->ymin;

    // Perform calculations to determine the value of the pixel
    fr_data->zx = fr_data->xmin + x * xdelta / fr_data->img_width;
    fr_data->zy = fr_data->ymin + y * ydelta / fr_data->img_height;;
    fr_data->iter = 0;
    while (pow(fr_data->zx, 2) + pow(fr_data->zy, 2) < 4 && fr_data->iter < fr_data->max_iter)
    {
        fr_data->new_re = pow(fr_data->zx, 2) - pow(fr_data->zy, 2) + fr_data->c_re;
        fr_data->new_im = 2 * fr_data->zx * fr_data->zy + fr_data->c_im;
        fr_data->zx = fr_data->new_re;
        fr_data->zy = fr_data->new_im;
        fr_data->iter++;
    }
    int color = set_color(fr_data->iter);
// Assign the value to the pixel in the image
mlx_put_pixel(fr_data->img, x, y, color);

return NULL;
}

void ft_julia(t_fr_data *fr_data)
{
	// double xdelta;
	// double ydelta;
	// xdelta = fr_data->xmax - fr_data->xmin;
	// ydelta = fr_data->ymax - fr_data->ymin;

	//Create a thread array to hold all the threads
	pthread_t threads[fr_data->img_width * fr_data->img_height];
	int thread_count = 0;

	// Iterate over the width and height of the image
	for (int i = 0; i < fr_data->img_width; i++) {
		for (int j = 0; j < fr_data->img_height; j++) {
			// Set the parameters for the thread
			t_pixel_thread_params thread_params = {i, j, fr_data};
			// Create the thread and pass it the parameters
			pthread_create(&threads[thread_count], NULL, calculate_pixel, &thread_params);
			thread_count++;
		}
	}
	// Wait for all the threads to finish executing
	for(int i = 0; i < thread_count; i++){
		pthread_join(threads[i], NULL);
	}
}
*/
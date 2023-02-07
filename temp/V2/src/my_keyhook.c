/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:55:12 by csenand           #+#    #+#             */
/*   Updated: 2023/02/06 21:48:08 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	double pi;
	
	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			data->ymin += .1;
			data->ymax += .1;
		}
		else
		{
			data->ymin += .2;
			data->ymax += .2;
		}     
		data->f(data);
	}
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			data->ymin -= .1;
			data->ymax -= .1;
		}
		else
		{
			data->ymin -= .2;
			data->ymax -= .2;
		}
		data->f(data);
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			data->xmin -= .1;
			data->xmax -= .1;
		}
		else
		{
			data->xmin -= .2;
			data->xmax -= .2;
		}
		data->f(data);
	}
	
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if(keydata.action == MLX_PRESS)
		{
			data->xmin += .1;
			data->xmax += .1;
		}
		else
		{
			data->xmin += .2;
			data->xmax += .2;
		}
		data->f(data);
	}
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
	{
		puts(YEL "\n Key Hooks (all sets)\n");
		puts(WHT "  esc		| Quit program");
		puts("  ⬆		| Move up");
		puts("  ⬇		| Move down");
		puts("  <->		| Move left|right");
		puts("  r		| change colors to "RED"red"WHT);
		puts("  g		| change colors to "GRN"green"WHT);
		puts("  b		| change colors to "BLU"blue"WHT);
		puts("  h		| Show help");
		puts("  mouse wheel	| Zoom in and out");
		puts(YEL "\n Key Hooks (Julia set)\n");
		puts(WHT"  z + mouse mvt	| change values to show different sets");

	}
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_REPEAT)
	{
		mlx_cursor_hook(data->mlx, &my_mouse_pos, data);
		printf("c_re : %f, c_im : %f\n", data->c_re, data->c_im);
		if ((data->c_re > -2 && data->c_re < 2) || (data->c_im > -2 && data->c_im < 2))
			data->f(data);
	}
	if (keydata.key == MLX_KEY_N && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		pi = 0;
		while (pi < 3.14)
		{
			data->c_re = 0.7885 * cos(pi);
			data->c_im = 0.7885 * sin(pi);
			pi += 0.01;
		}
		data->f(data);
		//pi = 0;
		//z^2 + 0.7885e^ia
		// where a range from 0 to 2*pi

		/*
		double a, real_z, imag_z, real_c, imag_c;

		for (a = 0; a <= 2 * M_PI; a += 0.01) {
			real_c = 0.7885 * cos(a);
			imag_c = 0.7885 * sin(a);

			double real_temp = real_z * real_z - imag_z * imag_z + real_c;
			imag_z = 2 * real_z * imag_z + imag_c;
			real_z = real_temp;

			printf("%f + %fi\n", real_z, imag_z);

			In this example, the variable a is used to iterate through the range of 0 to 2 * pi. 
			The constant c is represented by two separate variables, c_re and c_im,
			which are defined as 0.7885 * cos(a) and 0.7885 * sin(a) respectively using the cos() and sin() functions.
			 
			The variable z_re and z_im represent the real and imaginary parts of z respectively. 
			Then, the equation z^2 + c is implemented using the basic arithmetic operations and the variables 
			are updated accordingly. Finally, the real and imaginary parts of z are printed.

			As with the previous example, this is just a rough example, you will need to decide the number of iterations, 
			the range of a and the starting point of z to obtain the desired output. 
			Also, the above code will only give a point of the Julia set, you can use a library like libpng to draw 
			the Julia set on the screen, or use an array to store the values of z in order to draw the set later.
		*/
	}	
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_data	*data;
	
	data = (t_data *)param;
	if (ydelta > 0)
	{
		data->ymin *= 0.9;
		data->ymax *= 0.9;
		data->xmin *= 0.9;
		data->xmax *= 0.9;
		data->f(data);
	}	
	else if (ydelta < 0)
	{
		data->ymin *= 1.1;
		data->ymax *= 1.1;
		data->xmin *= 1.1;
		data->xmax *= 1.1;
		data->f(data);
	}
}

/*
void my_mouse_pos(double xmouse, double ymouse, void* param)
{
	t_data	*data;
	data = (t_data *)param;
	static int x;
	static int y;
	
	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x != data->x1 || y != data->y1)
	{		
		data->x1 = x;
		data->y1 = y;
		//return (1);
	}
	// return (0);
	
}
*/

void	my_mouse_pos(double xpos, double ypos, void* param)
{
	t_data	*data;
	
	data = (t_data *)param;
	data->c_re = xpos / data->img_width;
	data->c_im = ypos / data->img_height;
	//printf("x : %f, y : %f\n", xpos, ypos);
	// data->c_re = (sin(xpos) + 1) * 2 - 2;
	// data->c_im = (sin(xpos) + 1) * 2 - 2;
}
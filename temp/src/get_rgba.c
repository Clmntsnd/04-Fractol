#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int set_color(int c)
{
	int color;

	color = 0;
	if (c < 50)
		color = get_rgba(215,31,31,255); //red
	else if (c >= 50 && c <=100)
		color = get_rgba(255, 0, 255, 255);
	else
		color = get_rgba(0,0,0,255); //black
	return (color);
}
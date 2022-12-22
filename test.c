/*#include "MLX42/include/MLX42/MLX42.h"

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx42");
	mlx_loop(mlx_ptr);
}
*/


#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 500
#define HEIGHT 500

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	// pixel move by pressing a key
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5; 
}

int32_t	main(void)
{
	mlx_t	*mlx;

	// define window's properties [width; height; window's name; TBD]
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	// safety
	if (!mlx)
		exit(EXIT_FAILURE);
	
	// mlx_new_image(XX, [height in pixel], [width in pixel])
	g_img = mlx_new_image(mlx, 128, 128); 

	// memset(XX, [color code], [image's width] * [image's height] * sizeof(int))
	memset(g_img->pixels, 155, g_img->width * g_img->height * sizeof(int)); 
	
	//put the image onto the window
	mlx_image_to_window(mlx, g_img, 0, 0); 
	
	//put the image onto the window
	mlx_loop_hook(mlx, &hook, mlx);

	// 
	mlx_loop(mlx);

	mlx_terminate(mlx);

	// If everything went well, exit the program
	return (EXIT_SUCCESS);
}

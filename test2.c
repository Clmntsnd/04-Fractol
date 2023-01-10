#include "MLX42/include/MLX42/MLX42.h"
#include <memory.h>
#include <stdlib.h>


#define WIDTH 500
#define HEIGHT 500

/*
typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;
*/

//gcc test.c libmlx42.a libglfw3.a -o test -framework Cocoa -framework OpenGL -framework IOKit  


int	main(void)
{
	mlx_image_t *g_img;
	mlx_image_t *h_img;
	mlx_t		*mlx;

	/*
	**	Initialize a window by passing widht, height, its name, and if it can be resizable
	*/
	mlx = mlx_init(WIDTH, HEIGHT, "Hello World!", true);
	
	/* 
	**	Safety
	*/
	if (!mlx)
		exit(EXIT_FAILURE);
	
	/*
	**	Setting a image by passing the pointer to the window (where to put the image),
	**	its width and heigth 
	*/
	g_img = mlx_new_image(mlx, 120, 60); 
	h_img = mlx_new_image(mlx, 60, 120); 

	/*
	**	Allocating the right amount of memory, by giving to memset the pointer
	**	'pixels', the color '190', and the length 'g_img->width * g_img->height * sizeof(int)'
	*/
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	memset(h_img->pixels, 255, h_img->width * h_img->height * sizeof(int));
	
	/*
	**	Put image into the window and display it.  
	**	Passing values are the pointer to the window, the pointer to the image,
	**	and then the cordinates to where the image will start to render (from the top left).
	*/
	mlx_image_to_window(mlx, g_img, 15, 15);
	mlx_image_to_window(mlx, h_img, 150, 150);

	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_delete_image(mlx, h_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

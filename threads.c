
// Struct to hold the parameters for the thread
struct pixel_thread_params {
    int x;
    int y;
    t_fr_data* fr_data;
};

// Function to be executed by the thread
void* calculate_pixel(void* arg) {
    struct pixel_thread_params* params = (struct pixel_thread_params*) arg;
    int x = params->x;
    int y = params->y;
    t_fr_data* fr_data = params->fr_data;

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
	double xdelta;
	double ydelta;
	xdelta = fr_data->xmax - fr_data->xmin;
	ydelta = fr_data->ymax - fr_data->ymin;

	//Create a thread array to hold all the threads
	pthread_t threads[fr_data->img_width * fr_data->img_height];
	int thread_count = 0;

	// Iterate over the width and height of the image
	for (int i = 0; i < fr_data->img_width; i++) {
		for (int j = 0; j < fr_data->img_height; j++) {
			// Set the parameters for the thread
			struct pixel_thread_params thread_params = {i, j, fr_data};
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
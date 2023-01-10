#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
  double min_re = -2.0;
  double max_re = 1.0;
  double min_im = -1.0;
  double max_im = 1.0;
  double re_factor = (max_re - min_re) / (WIDTH - 1);
  double im_factor = (max_im - min_im) / (HEIGHT - 1);

  unsigned char buffer[HEIGHT][WIDTH];
  for (int y = 0; y < HEIGHT; y++) {
    double c_im = max_im - y * im_factor;
    for (int x = 0; x < WIDTH; x++) {
      double c_re = min_re + x * re_factor;
      double complex c = c_re + c_im * I;
      double complex z = c;
      int value = 0;
      int iterations = 0;
      while (cabs(z) < 2 && iterations < 100) {
        z = z * z + c;
        iterations++;
      }
      if (iterations == 100) {
        value = 0;
      } else {
        value = 255 - iterations;
      }
      buffer[y][x] = value;
    }
  }

  FILE *fp = fopen("mandelbrot.pgm", "w");
  fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buffer, sizeof(unsigned char), WIDTH * HEIGHT, fp);
  fclose(fp);

  return 0;
}

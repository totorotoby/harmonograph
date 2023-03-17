#include <stdlib.h>
#include <stdio.h>
#include "img.h"

void write_img(Img *img, char *filename)
{
  
  FILE *fout = fopen(filename, "w");
  fprintf(fout, "P6\n");
  fprintf(fout, "%d %d\n", img->width, img->height);
  fprintf(fout, "%d\n", 255);

  Pixel *pixels = img->pixels;

  for (int i = 0 ; i < img->height*img->width ; i++)
    {
      fprintf(fout, "%c%c%c",
	      pixels[i].R,
	      pixels[i].G,
	      pixels[i].B);
    }
  fclose(fout);
}

  
Img *new_blank_img(int height, int width){

  Img *img = malloc(sizeof(img));
  
  img->height = height;
  img->width = width;

  img->pixels = (Pixel *) malloc(sizeof(Pixel) * height * width);

  for (int i = 0 ; i < height ; ++i){
    for (int j = 0 ; j < width ; ++j){
      int idx = i * width + j;
      img->pixels[idx].R = 0;
      img->pixels[idx].G = 0;
      img->pixels[idx].B = 0;
      }
    }
  return img;
}

void write_pixel(Img *img, int idx, int color){
  
  img->pixels[idx].R = color >> 16;
  img->pixels[idx].G = (color >> 8) & ((1 << 4) - 1);
  img->pixels[idx].B = color & ((1 << 4) - 1);

}
  
void draw_point(Img *img, int x, int y, int color){


  int width = img->height;
  int img_x = width/2 + x;
  int img_y = img->height/2 + y;

  int idx = img_y * width + img_x;
  write_pixel(img, idx, color);
  
}

void draw_line(Img *img, int x1, int x2, int y1, int y2, int color){

  int slope = (y2 - y1) / (x2 - x1);
  
  int x_cur = x1;
  int y_cur = y1;
  while (x_cur < x2)
    {
      draw_point(img, x_cur, y_cur, color);
      int y_iter = 0;
      while(y_iter < slope){
	printf("(%d, %d)\n", x_cur, y_cur);
	draw_point(img, x_cur, y_cur + y_iter, color);
	y_cur ++;
	y_iter ++;
      }
      x_cur ++;
    }
}

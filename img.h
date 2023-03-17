typedef struct{
  
  unsigned char R;
  unsigned char G;
  unsigned char B;
   
} Pixel;

typedef struct{

  int height;
  int width;
  Pixel *pixels;
  
} Img;

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF


Img *new_blank_img(int height, int width);
void write_img(Img *img, char *filename);
void draw_point(Img *img, int x, int y, int color);
unsigned char red_channel(int color);
unsigned char green_channel(int color);
unsigned char blue_channel(int color);
void write_pixel(Img *img, int idx, int color);
void draw_line(Img *img, int x1, int x2, int y1, int y2, int color);


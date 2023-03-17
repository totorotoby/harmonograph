#include "img.h"
#include <stdio.h>
#include "harmonograph.h"

int main(){

  int height = 4000;
  int width = 4000;

  
  Img *img = new_blank_img(height, width);

  peng1d px;
  peng1d py;
  
  peng_init(&px, 800.0, 1.5, .01);
  peng_init(&py, 1200.0, 2.0, .001);
  render_2_1d_peng(img, &px, &py, .001, 1000000);
  write_img(img, "hmm.ppm");

}
 

#include "img.h"
#include "math.h"
#include "harmonograph.h"

void peng_init(peng1d *p, double amp, double freq, double damp){
  p->amp = amp;
  p->freq = freq;
  p->damp = damp;
}

double p1d_state(peng1d *peng, double t){
  return peng->amp * sin(peng->freq * t) * exp(-peng->damp * t);
}

void render_2_1d_peng(Img *img, peng1d *px, peng1d *py, double dt, int N){
		      
  for (int t = 0; t < N ; t++)
    {
      draw_point(img,
		 p1d_state(px, t*dt),
		 p1d_state(py, t*dt),
		 0xFF0000);
    }
}

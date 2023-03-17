typedef struct{

  double amp;
  double freq;
  double damp;
  
} peng1d;

double p1d_state(peng1d *peng, double t);
void render_2_1d_peng(Img *img, peng1d *px, peng1d *py, double dt, int N);
void peng_init(peng1d *p, double amp, double freq, double damp);

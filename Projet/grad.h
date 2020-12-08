#ifdef _grad_h_
#define _grad_h_

float moyenne2Points(float a, float b);
double getIntensityPixel(double** mat,int x,int y);
double gradx(double** mat,int x,int y);
double grady(double** mat,int x,int y);
double gradt(double** mat1,double** mat2,int x,int y);
void fillGradX(double** Intensite,double** matRes,int dimX,int dimY);
#endif // _grad_h_

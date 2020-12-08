#ifndef _grad_h_
#define _grad_h_
#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
float moyenne2Points(float a, float b);
double getIntensityPixel(double** mat,int x,int y);
double gradx(double** mat,int x,int y,int dimX);
double grady(double** mat,int x,int y,int dimY);
double gradt(double** mat1,double** mat2,int x,int y);
void fillGradX(double** Intensite, double** matRes,int dimX,int dimY);
void fillGradY(double** Intensite, double** matRes,int dimX,int dimY);
void fillGrad_t(double** Intensite1,double** Intensite2, double** matRes,int dimX,int dimY);
#endif // _grad_h_

#ifndef _SpeedCalculator_h_
#define _SpeedCalculator_h_

#include "matrice.h"
#include "Umoy.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** u(double** GradientX,double** GradientY,double** GradientT,int dimX,int dimY,float alpha);

#endif

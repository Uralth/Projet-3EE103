#ifndef _SpeedCalculator2_h_
#define _SpeedCalculator2_h_

#include "matrice.h"
#include "Umoy.h"
#include "portfolio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Calcul des vitesses de l'image dans une seule structure
  * @param Gradient X de l'image
  * @param Gradient Y de l'image
  * @param Gradient en temps de l'image
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  * @param Parametre alpha de ponderation
  */
PrtVue vit(double** GradientX,double** GradientY,double** GradientT,int dimX,int dimY,float alpha);

#endif

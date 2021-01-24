#ifndef _grad_h_
#define _grad_h_
#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>

/** Distance entre 2 points
  * @param Premier point
  * @param Deuxieme point
  */
float distance2Points(float a, float b);

/** Intensite d'un pixel
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  */
double getIntensityPixel(double** mat,int x,int y);

/** Gradient en X
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  * @param Dimension X de l'image
  */
double gradx(double** mat,int x,int y,int dimX);

/** Gradient en Y
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  * @param Dimension Y de l'image
  */
double grady(double** mat,int x,int y,int dimY);

/** Gradient en Temps
  * @param Matrice des pixels de l'image source
  * @param Matrice des pixels de l'image source 2
  * @param Position X du pixel
  * @param Position Y du pixel
  */
double gradt(double** mat1,double** mat2,int x,int y);

/** Remplissage d'une matrice de gradients en X
  * @param Matrice des pixels de l'image source
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGradX(double** Intensite, double** matRes,int dimX,int dimY);

/** Remplissage d'une matrice de gradients en Y
  * @param Matrice des pixels de l'image source
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGradY(double** Intensite, double** matRes,int dimX,int dimY);

/** Remplissage d'une matrice de gradients en temps
  * @param Matrice des pixels de l'image source
  * @param Matrice des pixels de l'image source 2
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGrad_t(double** Intensite1,double** Intensite2, double** matRes,int dimX,int dimY);
#endif

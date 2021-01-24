#ifndef _matrice_h_
#define _matrice_h_

#include <stdlib.h>
#include <stdio.h>
#include "myBmpGris.h"


/** Construction de Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
double** createMatrice(int dimX, int dimY);

/** Remplissage de matrice avec une valeur particuli�re
  * @param Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param valeur
  */
void fillMatrice(double** matrice, int dimX, int dimY, double value);

/**Destruction de Matrice
  * @param Matrice � detruire
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void destroyMatrice(double** matrice, int dimX, int dimY);

/** Impression de matrice
  * @param Matrice � imprimer
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void printMatrice(double** matrice, int dimX, int dimY);

/** Conversion bmp vers une matrice de double
  * @param Structure d'une image de type Bmp � convertir
  */
double** bmpToMatrice(BmpImg bmpImg);

/** Ecriture sur un fichier texte
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param Fichier a remplir
  */
void MatriceToTxt(double** matrice, int dimX, int dimY, FILE *fichier);

/** Echantillon par un facteur n
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param facteur d'�chantillonnage
  */
double** sampleMatrix(double** matrice, int dimX, int dimY, int n);

#endif

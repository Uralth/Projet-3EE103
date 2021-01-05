#ifndef _matrice_h_
#define _matrice_h_

#include <stdlib.h>
#include <stdio.h>
#include "myBmpGris.h"


// Construction de Matrice
double** createMatrice(int dimX, int dimY);

// Destruction de Matrice
void destroyMatrice(double** matrice, int dimX, int dimY);

// Impression de matrice
void printMatrice(double** matrice, int dimX, int dimY);

//copie de matrice de taille égale
void copieMatrice(double** mat1,double** mat2,int dimX,int dimY);

// Conversion bmp vers une matrice de double
double** bmpToMatrice(BmpImg bmpImg);



#endif


//extern struct BmpImg BmpImg;

/*typedef struct{
	int dimX;	    // Dimension en x (hauteur)
	int dimY;		// Dimension en y (largeur)
	double** data;	// Matrice contenant les données (double)
} Matrice;*/


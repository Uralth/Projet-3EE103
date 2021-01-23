/*
Ces fonctions et structures ont été crées afin de prendre en charge les matrices de u moyens
et v moyens du coup ne tenez pas compte du nom arbitraire
*/

#ifndef _Umoy_h_
#define _Umoy_h_

    #include "matrice.h"
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>

	typedef struct Umoy Umoy;
	struct Umoy{
		int dimX,dimY,n;
		double** Somme;
		double** U_moy;
	};

	Umoy InitUmoy(int dimX,int dimY);
	/*
	initialisation de la matrice Umoy et Somme avec des 0 et avec n=0
	(n : nombre de termes stockés dans chaque case)
	*/

	double calcMoyCase(double** u,int sizeX, int sizeY);
	/*
	calcul de la moyenne de toute les cases du tableau
	*/

	void UpdateMoy(Umoy* U,double** u);
	/*
	sert à mettre à jour les matrices de somme et de moyenne
	ainsi que le nombre de termes stockés
	*/

#endif

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

    /** Initialisation des matrices Umoy et Somme à 0
    * @param Dimension X
    * @param Dimension Y
    * @return Umoy initialisée a 0
    */
	Umoy InitUmoy(int dimX,int dimY);
	/*
	initialisation de la matrice Umoy et Somme avec des 0 et avec n=0
	(n : nombre de termes stockés dans chaque case)
	*/

    /** Calcul de la moyenne de toutes les cases du tableau
    * @param Tableau source
    * @param Dimension X
    * @param Dimension Y
    * @return Valeur moyenne
    */
	double calcMoyCase(double** u,int sizeX, int sizeY);

	/** Met a jour les parametres de somme et de moyenne, et nombre de termes stockés
    * @param U moyen
    * @param Tableau source
    */
	void UpdateUmoy(Umoy* U,double** u);


#endif

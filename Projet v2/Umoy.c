#include "Umoy.h"

/** Initialisation des matrices Umoy et Somme à 0
* @param Dimension X
* @param Dimension Y
* @return Umoy initialisée a 0
*/
Umoy InitUmoy(int dimX,int dimY){
	Umoy res;

	res.n = 1;
	res.dimX = dimX;
	res.dimY = dimY;
	res.Somme = createMatrice(dimX,dimY);
	res.U_moy = createMatrice(dimX,dimY);

	return res;
}

/** Calcul de la moyenne de toutes les cases du tableau
  * @param Tableau source
  * @param Dimension X
  * @param Dimension Y
  * @return Valeur moyenne
  */
double calcMoyCase(double** u,int sizeX, int sizeY){
    int i,j;
    double res =0.0;
    for (i=0;i<sizeX;i++){
		for (j=0;j<sizeY;j++){
		    res+=u[i][j];
		}
    }
    return res/(sizeX*sizeY);
}

/** Met a jour les parametres de somme et de moyenne, et nombre de termes stockés
  * @param U moyen
  * @param Tableau source
  */
void UpdateUmoy(Umoy* U,double** u){
	int i,j;
	(U->n) += 1;
	for (i=0;i<U->dimX;i++){
		for (j=0;j<U->dimY;j++){
			U->Somme[i][j] += u[i][j];
			U->U_moy[i][j] = (U->Somme[i][j])/(U->n);
		}
	}
}

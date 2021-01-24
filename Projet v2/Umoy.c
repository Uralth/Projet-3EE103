#include "Umoy.h"

/** Initialisation des matrices Umoy et Somme à 0
* @param Dimension X
* @param Dimension Y
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

/** Met a jour les parameptres de somme et de moyenne, et nombre de termes stockés
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

// void test(int dimX,int dimY){
// 	int i,j;
// 	Umoy uMoy = InitUmoy(dimX,dimY);
// 	double** test = createMatrice(dimX,dimY);                     // lignes
//     for (i=0;i<uMoy.dimX;i++){
// 		for (j=0;j<uMoy.dimY;j++){
// 			test[i][j] = 1.0;
// 		}
// 	}
// 	printf("=================test(av Update)=============\n");
// 	printMatrice(uMoy.U_moy,dimX,dimY);
// 	UpdateUmoy(uMoy,test);
// 	printf("=================Somme(av Update)=============\n");
// 	printMatrice(uMoy.Somme,dimX,dimY);
// 	printf("=================test(av Update)=============\n");
// 	printMatrice(uMoy.U_moy,dimX,dimY);
// }

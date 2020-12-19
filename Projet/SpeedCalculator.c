#include "SpeedCalculator.h"

double** u(double** GradientX,double** GradientY,double** GradientT,int dimX,int dimY,float alpha){
	/* rajouter la marge d'erreur*/
	int i,j;
	double** u_moy = createMatrice(dimX,dimY);
	double** res;
	double Ix,Iy,It;
    //printf("est rentré dans la fonction\n");
	res = malloc(dimX*sizeof(double*));                     // lignes
    for(i = 0; i < dimX; i++){
        res[i] = calloc(dimY, sizeof(double));              // colonnes
    }
    printMatrice(u_moy,dimX,dimY);
    //printf("==============================mat cree:\n");
    //printMatrice(res,dimX,dimY);
	for (i=0;i<dimX;i++){
		for (j=0;j<dimY;j++){
			//printf("==============================\n");
			Ix = GradientX[i][j];
			Iy = GradientY[i][j];
			It = GradientT[i][j];
			res[i][j] = u_moy[i][j]-(Ix*(Ix*u_moy[i][j]+Iy*u_moy[i][j]+It)/(alpha+Ix*Ix+Iy*Iy));
			u_moy[i][j] = res[i][j];
			//printMatrice(res,dimX,dimY);
            //printf("ca marche l\n");
            //printf("x = %d\n",i);
            //printf("y = %d\n",j);
		}
		//printf("ca marche colonne changee\n");
	}
	printf("=================umoy=============\n");
	printMatrice(u_moy,dimX,dimY);
	return res;
}

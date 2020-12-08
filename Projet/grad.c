#include "grad.h"
#include "matrice.h"

double distance2Points(double a, double b){
    //retourne la distance entre 2 points a et b
    return (a-b)/2;
}

double getIntensityPixel(double** mat,int x,int y){
    //retourne l'intensité dans un pixel
    return mat[x][y];
}

double gradx(double** mat,int x, int y){
    //retourne le gradient selon l'axe x
    if (x==0){
        return getIntensityPixel(mat,x+1,y)/2;
    }
    else{
        return distance2Points(getIntensityPixel(mat,x+1,y),getIntensityPixel(mat,x-1,y));
    }
}

double grady(double** mat,int x, int y){
    //retourne le gradient selon l'axe y
    if (y==0){
        return getIntensityPixel(mat,x,y+1)/2;
    }
    else{
        return distance2Points(getIntensityPixel(mat,x,y+1),getIntensityPixel(mat,x,y-1));
    }
}

double gradt(double** mat1,double** mat2,int x, int y){
    //retourne le gradient selon le temps
    return getIntensityPixel(mat1,x,y)-getIntensityPixel(mat2,x,y);
}

void fillGradX(double** Intensite,double** matRes,int dimX,int dimY){
	int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            //printf("==============================\n");
            //printMatrice(matRes,dimX,dimY);
            //printf("ca marche\n");

			matRes[x][y] = gradx(Intensite,x,y);
		}
	}
}

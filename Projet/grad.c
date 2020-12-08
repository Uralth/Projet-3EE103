#include "matrice.h"

double distance2Points(double a, double b){
    //retourne la distance entre 2 points a et b
    return (a-b)/2;
}

double getIntensityPixel(double** mat,int x,int y){
    //retourne l'intensité dans un pixel
    return mat[x][y];
}

double gradX(double** mat,int x, int y,int dimX){
    //retourne le gradient selon l'axe x
    if (x==0){
        return getIntensityPixel(mat,x+1,y)/2;
    }
    if (x==dimX-1){
        return getIntensityPixel(mat,x-1,y)/2;
    }
    else{
        return distance2Points(getIntensityPixel(mat,x+1,y),getIntensityPixel(mat,x-1,y));
    }
}

double gradY(double** mat,int x, int y,int dimY){
    //retourne le gradient selon l'axe y
    if (y==0){
        return getIntensityPixel(mat,x,y+1)/2;
    }
    if (y==dimY-1){
        return getIntensityPixel(mat,x,y-1)/2;
    }
    else{
        return distance2Points(getIntensityPixel(mat,x,y+1),getIntensityPixel(mat,x,y-1));
    }
}

double grad_t(double** mat1,double** mat2,int x, int y){
    //retourne le gradient selon le temps
    return getIntensityPixel(mat2,x,y)-getIntensityPixel(mat1,x,y);
}

void fillGradX(double** Intensite,double** matRes,int dimX,int dimY){
	int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            //printf("==============================\n");
            matRes[x][y] = gradX(Intensite,x,y,dimX);
            // printMatrice(matRes,dimX,dimY);
            // printf("ca marche l\n");
            // printf("x = %d\n",x);
            // printf("y = %d\n",y);


		}
		//printf("ça marche colonne changee\n");
	}
}

void fillGradY(double** Intensite,double** matRes,int dimX,int dimY){
	int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            // printf("==============================\n");
            matRes[x][y] = gradY(Intensite,x,y,dimY);
            // printMatrice(matRes,dimX,dimY);
            // printf("ca marche l\n");
            // printf("x = %d\n",x);
            // printf("y = %d\n",y);
		}
		// printf("ca marche colonne changee\n");
	}
}

void fillGrad_t(double** Intensite1,double** Intensite2,double** matRes,int dimX,int dimY){
    int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            //printf("==============================\n");
            matRes[x][y] = grad_t(Intensite1,Intensite2,x,y);
            //printMatrice(matRes,dimX,dimY);
            //printf("ca marche l\n");
            //printf("x = %d\n",x);
            //printf("y = %d\n",y);
		}
		printf("ca marche colonne changee\n");
	}
}

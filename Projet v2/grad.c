#include "matrice.h"

/** Distance entre 2 points
  * @param Premier point
  * @param Deuxieme point
  */
double distance2Points(double a, double b){
    return (a-b)/2;
}

/** Intensite d'un pixel
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  */
double getIntensityPixel(double** mat,int x,int y){
    return mat[x][y];
}

/** Gradient en X
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  * @param Dimension X de l'image
  */
double gradX(double** mat,int x, int y,int dimX){
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

/** Gradient en Y
  * @param Matrice des pixels de l'image source
  * @param Position X du pixel
  * @param Position Y du pixel
  * @param Dimension Y de l'image
  */
double gradY(double** mat,int x, int y,int dimY){
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

/** Gradient en Temps
  * @param Matrice des pixels de l'image source
  * @param Matrice des pixels de l'image source 2
  * @param Position X du pixel
  * @param Position Y du pixel
  */
double grad_t(double** mat1,double** mat2,int x, int y){
    return getIntensityPixel(mat2,x,y)-getIntensityPixel(mat1,x,y);
}

/** Remplissage d'une matrice de gradients en X
  * @param Matrice des pixels de l'image source
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGradX(double** Intensite,double** matRes,int dimX,int dimY){
	int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            matRes[x][y] = gradX(Intensite,x,y,dimX);
		}
	}
}

/** Remplissage d'une matrice de gradients en Y
  * @param Matrice des pixels de l'image source
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGradY(double** Intensite,double** matRes,int dimX,int dimY){
	int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            matRes[x][y] = gradY(Intensite,x,y,dimY);
		}
	}
}

/** Remplissage d'une matrice de gradients en temps
  * @param Matrice des pixels de l'image source
  * @param Matrice des pixels de l'image source 2
  * @param Matrice resultante
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
void fillGrad_t(double** Intensite1,double** Intensite2,double** matRes,int dimX,int dimY){
    int x,y;
	for(y=0;y<dimY;y++){
		for(x=0;x<dimX;x++){
            matRes[x][y] = grad_t(Intensite1,Intensite2,x,y);
		}
	}
}

#include "matrice.h"


// Construction de Matrice
double** createMatrice(int dimX, int dimY){
    int i;
    double** res;                                           // résultat
    res = malloc(dimX*sizeof(double*));                     // lignes
    for(i = 0; i < dimX; i++){
        res[i] = calloc(dimY, sizeof(double));              // colonnes
    }
    return res;
}

// Destruction de Matrice
void destroyMatrice(double** matrice, int dimX, int dimY){
    int i;
    for(i =0; i < dimX; i++){
        free(matrice[i]);
    }
    free(matrice);
    matrice = NULL;
}

// Impression de matrice
void printMatrice(double** matrice, int dimX, int dimY){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            printf("%.2f\t", matrice[i][j]);                //affichage du pixel
        }
        printf("\n");
    }
}
// Copie de matrice de taille égale
void copieMatrice(double** mat1,double** mat2,int dimX,int dimY){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            mat2[i][j] = mat1[i][j]; //copie des éléments de mat1 dans mat2
        }
    }
}

// Conversion bmp vers une matrice de double
double** bmpToMatrice(BmpImg bmpImg){
    int i, j;
    double** res = createMatrice(bmpImg.dimX, bmpImg.dimY); //initialisation résultat
    for(i = 0; i < bmpImg.dimX; i++){
        for(j = 0; j < bmpImg.dimY; j++){
            res[i][j] = 1.0*getPixel(bmpImg, i, j);         //recuperation valeur pixel aux coord correspondantes
        }
    }
    return res;
}

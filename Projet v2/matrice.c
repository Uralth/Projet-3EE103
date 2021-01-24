#include "matrice.h"


/** Construction de Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @return Matrice initialisée à 0
  */
double** createMatrice(int dimX, int dimY){
    int i;
    double** res;                                           // résultat
    res = malloc(dimX*sizeof(double*));                     // lignes
    for(i = 0; i < dimX; i++){
        res[i] = calloc(dimY, sizeof(double));              // colonnes
    }
    return res;
}

/** Remplissage de matrice avec une valeur particulière
  * @param Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param valeur
  */
void fillMatrice(double** matrice, int dimX, int dimY, double value){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            matrice[i][j] = value;                //valeur dans la matrice
        }
    }
}

/**Destruction de Matrice
  * @param Matrice à detruire
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void destroyMatrice(double** matrice, int dimX, int dimY){
    int i;
    for(i =0; i < dimX; i++){
        free(matrice[i]);
    }
    free(matrice);
    matrice = NULL;
}

/** Impression de matrice
  * @param Matrice à imprimer
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void printMatrice(double** matrice, int dimX, int dimY){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            printf("%.2f\t", matrice[i][j]);                //affichage du pixel
        }
        printf("\n");
    }
}

/** Conversion bmp vers une matrice de double
  * @param Structure d'une image de type Bmp à convertir
  * @return Matrice correspondant a l'image
  */
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

/** Ecriture sur un fichier texte
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param Fichier a remplir
  */
void MatriceToTxt(double** matrice, int dimX, int dimY, FILE *fichier){
    int i, j;
    fprintf(fichier, "%d\t%d\n", dimX, dimY);               //écriture des dimensions
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            fprintf(fichier,"%.2f\t", matrice[i][j]);               //écriture du pixel
        }
        fprintf(fichier,"\n");
    }
}

/** Echantillon par un facteur n
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param facteur d'échantillonnage
  * @return matrice echantillonnee
  */
double** sampleMatrix(double** matrice, int dimX, int dimY, int n){
    int i, j;
    double** res = createMatrice(dimX/n, dimY/n);
    for(i = 0; i < dimX/n; i++){
        for(j = 0; j < dimY/n; j++){
            res[i][j] = matrice[i*n][j*n];
        }
    }
    return res;
}

/** Interpolation de matrice d'un facteur n
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param facteur d'échantillonnage
  * @return Matrice interpolee
  */
double** simpleMatrixInterpolation(double** matrice, int dimX, int dimY, int n){
    int i, j;
    double** res = createMatrice(dimX, dimY);
    for(i = 0; i < dimX/n; i++){
        for(j = 0; j < dimY/n; j++){
            res[i*n][j*n] = matrice[i][j]*n;    // ajustement de la valeur par le facteur initial

        }
    }
    return res;
}


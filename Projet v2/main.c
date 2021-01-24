#include "matrice.h"
#include "SpeedCalculator2.h"
#include "grad.h"
#include "Umoy.h"
#include "portfolio.h"
#define FILENAME "Untitled.bmp"
#define FILENAME2 "Untitled_2.bmp"
#define FILENAME3 "Untitled.txt"
#define FILENAME4 "Untitled 2.txt"
#define N 2

int main(){
    FILE *fichierTxt;
    FILE *fichierTxt2;
    BmpImg image = readBmpImage(FILENAME);
    BmpImg image2= readBmpImage(FILENAME2);
    double** matrice = bmpToMatrice(image);
    double** matrice2 = bmpToMatrice(image2);
    double** matrice3;
    double** matrice4;
    double** matriceGradX = createMatrice(image.dimX,image.dimY);
    double** matriceGradY = createMatrice(image.dimX,image.dimY);
    double** matriceGrad_t= createMatrice(image.dimX,image.dimY);

    double** matriceGradX2 = createMatrice(image.dimX/N,image.dimY/N);
    double** matriceGradY2 = createMatrice(image.dimX/N,image.dimY/N);
    double** matriceGrad_t2= createMatrice(image.dimX/N,image.dimY/N);

    double** vit2 = createMatrice(image.dimX,image.dimY);
    PrtVue vit1;
    PrtVue vitBis;

    /* initialisation de structure pour umoy*/
    //Umoy u_m = InitUmoy(image.dimX,image.dimY);;
    //printMatrice(matrice, image.dimX, image.dimY);

    /* initialisation des matrices de gradients */
    fillGradX(matrice,matriceGradX,image.dimX,image.dimY);
    fillGradY(matrice,matriceGradY,image.dimX,image.dimY);
    fillGrad_t(matrice,matrice2,matriceGrad_t,image.dimX,image.dimY);

    fichierTxt = fopen(FILENAME3, "w");
    fichierTxt2 = fopen(FILENAME4, "w");

    /* Calcul de u */
    vit1 = vit(matriceGradX,matriceGradY,matriceGrad_t,image.dimX,image.dimY,3.0);
    //    printf("=================Grad X=============\n");
    //    printMatrice(matriceGradX, image.dimX, image.dimY);
    //    printf("=================Grad Y=============\n");
    //    printMatrice(matriceGradY, image.dimX, image.dimY);
    //    printf("=================Grad t=============\n");
    //    printMatrice(matriceGrad_t, image.dimX, image.dimY);
    printf("=============== u ===============\n");
    printMatrice(vit1.u, image.dimX, image.dimY);

    printf("\n=============== v ===============\n");
    printMatrice(vit1.v, image.dimX, image.dimY);
    //printf("=================test=============\n");
    //printf("moyenne = %f",calcMoyCase(matriceGradX, image.dimX, image.dimY));
    //printMatrice(u_m.U_moy,image.dimX,image.dimY);


//    //Ecriture dans les fichiers
//    printf("\nEcriture des matrices dans les fichiers...\n");
//    if( fichierTxt != NULL ) {
//        MatriceToTxt(vit1.u, image.dimX, image.dimY,fichierTxt);
//        fclose(fichierTxt);
//        printf("\nEcriture dans fichier 1 finie\n");
//    } else { // Sinon on affiche un message
//        printf ( "Erreur d'ouverture du fichier 1 !\n" );
//    }
//
//    if( fichierTxt2 != NULL ) {
//        MatriceToTxt(vit1.v, image.dimX, image.dimY,fichierTxt2);
//        fclose(fichierTxt2);
//        printf("\nEcriture dans fichier 2 finie\n");
//    } else { // Sinon on affiche un message
//        printf ( "Erreur d'ouverture du fichier 2 !\n" );
//    }

//    printMatrice(matrice, image.dimX, image.dimY);
    printf ( "\nTests Multi echantillons\n" );
    matrice3 = sampleMatrix(matrice,image.dimX, image.dimY,N);
    matrice4 = sampleMatrix(matrice2,image.dimX, image.dimY,N);
//    printMatrice(matrice3, image.dimX/N, image.dimY/N);
//    printf ( "\n" );
//    printMatrice(matrice4, image.dimX/N, image.dimY/N);

    fillGradX(matrice3,matriceGradX2,image.dimX/N,image.dimY/N);
    fillGradY(matrice3,matriceGradY2,image.dimX/N,image.dimY/N);
    fillGrad_t(matrice3,matrice4,matriceGrad_t2,image.dimX/N,image.dimY/N);

    vitBis = vit(matriceGradX2,matriceGradY2,matriceGrad_t2,image.dimX/N,image.dimY/N,1.0);

//    printf("=============== u ===============\n");
//    printMatrice(vitBis.u, image.dimX/N, image.dimY/N);
//
//    printf("\n=============== v ===============\n");
//    printMatrice(vitBis.v, image.dimX/N, image.dimY/N);

    vitBis.u = simpleMatrixExtrapolation(vitBis.u,image.dimX, image.dimY,N);
    vitBis.v = simpleMatrixExtrapolation(vitBis.v,image.dimX, image.dimY,N);

    printf("=============== u ===============\n");
    printMatrice(vit1.u, image.dimX, image.dimY);

    printf("\n=============== v ===============\n");
    printMatrice(vit1.v, image.dimX, image.dimY);

    //Ecriture dans les fichiers
    printf("\nEcriture des matrices dans les fichiers...\n");
    if( fichierTxt != NULL ) {
        MatriceToTxt(vitBis.u, image.dimX, image.dimY,fichierTxt);
        fclose(fichierTxt);
        printf("\nEcriture dans fichier 1 finie\n");
    } else { // Sinon on affiche un message
        printf ( "Erreur d'ouverture du fichier 1 !\n" );
    }

    if( fichierTxt2 != NULL ) {
        MatriceToTxt(vitBis.v, image.dimX, image.dimY,fichierTxt2);
        fclose(fichierTxt2);
        printf("\nEcriture dans fichier 2 finie\n");
    } else { // Sinon on affiche un message
        printf ( "Erreur d'ouverture du fichier 2 !\n" );
    }


    //Nettoyage
    freeBmpImg(&image);
    freeBmpImg(&image2);
    destroyMatrice(matrice, image.dimX,image.dimY);
    destroyMatrice(matrice2, image.dimX,image.dimY);
    destroyMatrice(matriceGradX, image.dimX,image.dimY);
    destroyMatrice(matriceGradY, image.dimX,image.dimY);
    destroyMatrice(matriceGrad_t, image.dimX,image.dimY);
    destroyMatrice(vit2, image.dimX,image.dimY);
    destroyMatrice(vit1.u, image.dimX,image.dimY);
    destroyMatrice(vit1.v, image.dimX,image.dimY);
    return 0;
}

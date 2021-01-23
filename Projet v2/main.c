#include "matrice.h"
#include "SpeedCalculator2.h"
#include "grad.h"
#include "Umoy.h"
#include "portfolio.h"
#define FILENAME "Untitled.bmp"
#define FILENAME2 "Untitled_2.bmp"
#define FILENAME3 "Untitled.txt"
#define FILENAME4 "Untitled 2.txt"

int main(){
    FILE *fichierTxt;
    FILE *fichierTxt2;
    BmpImg image = readBmpImage(FILENAME);
    BmpImg image2= readBmpImage(FILENAME2);
    double** matrice = bmpToMatrice(image);
    double** matrice2= bmpToMatrice(image2);
    double** matriceGradX = createMatrice(image.dimX,image.dimY);
    double** matriceGradY = createMatrice(image.dimX,image.dimY);
    double** matriceGrad_t= createMatrice(image.dimX,image.dimY);
    double** vit2 = createMatrice(image.dimX,image.dimY);
    PrtVue vit1;

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
    printf("=================u=============\n");
    printMatrice(vit1.u, image.dimX, image.dimY);
    //printf("=================test=============\n");
    //printf("moyenne = %f",calcMoyCase(matriceGradX, image.dimX, image.dimY));
    //printMatrice(u_m.U_moy,image.dimX,image.dimY);
    if( fichierTxt != NULL ) {
        MatriceToTxt(vit1.u, image.dimX, image.dimY,fichierTxt);
    } else { // Sinon on affiche un message
        printf ( " Erreur d'ouverture du fichier !" );
    }

    if( fichierTxt2 != NULL ) {
        MatriceToTxt(vit1.v, image.dimX, image.dimY,fichierTxt2);
    } else { // Sinon on affiche un message
        printf ( " Erreur d'ouverture du fichier !" );
    }

    freeBmpImg(&image);
    freeBmpImg(&image2);
    return 0;
}

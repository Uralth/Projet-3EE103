#include "matrice.h"
#include "grad.h"
#define FILENAME "Untitled.bmp"
#define FILENAME2 "Untitled 2.bmp"

int main(){
    BmpImg image = readBmpImage(FILENAME);
    double** matrice = bmpToMatrice(image);
    BmpImg image2 = readBmpImage(FILENAME2);
    double** matrice2 = bmpToMatrice(image2);
    double** matriceGradX = createMatrice(image.dimX,image.dimY);
    double** matriceGradY = createMatrice(image.dimX,image.dimY);
    double** matriceGrad_t= createMatrice(image.dimX,image.dimY);

    printMatrice(matrice, image.dimX, image.dimY);
    printf("\n");
    printMatrice(matrice2, image2.dimX, image2.dimY);

    printf("\n");

    fillGradX(matrice,matriceGradX,image.dimX,image.dimY);
    fillGradY(matrice,matriceGradY,image.dimX,image.dimY);
    fillGrad_t(matrice,matrice2,matriceGrad_t,image.dimX,image.dimY);

    printf("\n");
    printMatrice(matriceGradX, image.dimX, image.dimY);
    printf("\n");
    printMatrice(matriceGradY, image.dimX, image.dimY);
    printf("\n");
    printMatrice(matriceGrad_t, image.dimX, image.dimY);



    //nettoyage
    destroyMatrice(matrice, image.dimX, image.dimY);
    destroyMatrice(matrice2, image2.dimX, image2.dimY);
    destroyMatrice(matriceGradX, image.dimX, image.dimY);
    destroyMatrice(matriceGradY, image2.dimX, image2.dimY);
    destroyMatrice(matriceGrad_t, image2.dimX, image2.dimY);
    freeBmpImg(&image);
    freeBmpImg(&image2);
    return 0;
}

#include "matrice.h"
#include "grad.h"
#define FILENAME "Untitled.bmp"
#define FILENAME2 "Untitled 2.bmp"

int main(){
    BmpImg image = readBmpImage(FILENAME);
    setPixel(image,0,2,0);
    double** matrice = bmpToMatrice(image);
    BmpImg image2 = readBmpImage(FILENAME2);
    double** matrice2 = bmpToMatrice(image2);
    double** matriceGradX = createMatrice(image.dimX,image.dimY);

    printMatrice(matrice, image.dimX, image.dimY);
    printf("\n");
    printMatrice(matrice2, image2.dimX, image2.dimY);

    printf("\n");
    fillGradX(matrice,matriceGradX,image.dimX,image.dimY);
    printf("lol");
    printMatrice(matriceGradX, image.dimX, image.dimY);



    //nettoyage
    destroyMatrice(matrice, image.dimX, image.dimY);
    destroyMatrice(matrice2, image2.dimX, image2.dimY);
    freeBmpImg(&image);
    freeBmpImg(&image2);
    return 0;
}

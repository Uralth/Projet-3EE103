#include "matrice.h"
#include "SpeedCalculator.h"
#include "grad.h"
#define FILENAME "Untitled.bmp"
#define FILENAME2 "Untitled_2.bmp"

int main(){
    BmpImg image = readBmpImage(FILENAME);
    BmpImg image2= readBmpImage(FILENAME2);
    double** matrice = bmpToMatrice(image);
    double** matrice2= bmpToMatrice(image2);
    double** matriceGradX = createMatrice(image.dimX,image.dimY);
    double** matriceGradY = createMatrice(image.dimX,image.dimY);
    double** matriceGrad_t= createMatrice(image.dimX,image.dimY);
    double** vit2 = createMatrice(image.dimX,image.dimY);
    double** vit;
    //printMatrice(matrice, image.dimX, image.dimY);
    fillGradX(matrice,matriceGradX,image.dimX,image.dimY);
    fillGradY(matrice,matriceGradY,image.dimX,image.dimY);
    fillGrad_t(matrice,matrice2,matriceGrad_t,image.dimX,image.dimY);
    vit = u(matriceGradX,matriceGradY,matriceGrad_t,image.dimX,image.dimY,1.0);
    copieMatrice(vit,vit2,image.dimX,image.dimY);
//    printf("=================Grad X=============\n");
//    printMatrice(matriceGradX, image.dimX, image.dimY);
//    printf("=================Grad Y=============\n");
//    printMatrice(matriceGradY, image.dimX, image.dimY);
//    printf("=================Grad t=============\n");
//    printMatrice(matriceGrad_t, image.dimX, image.dimY);
    printf("=================u=============\n");
    printMatrice(vit, image.dimX, image.dimY);
    freeBmpImg(&image);
    return 0;
}

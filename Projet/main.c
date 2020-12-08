#include "matrice.h"
#define FILENAME "Untitled.bmp"

int main(){
    BmpImg image = readBmpImage(FILENAME);
    double** matrice = bmpToMatrice(image);
    printMatrice(matrice, image.dimX, image.dimY);
    freeBmpImg(&image);
    return 0;
}

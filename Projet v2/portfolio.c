#include "portfolio.h"

/** Initialisation d'un conteneur pour les vitesses
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  */
PrtVue InitPrtVue(int dimX, int dimY){
	PrtVue res;

	res.u = createMatrice(dimX, dimY);
	res.v = createMatrice(dimX, dimY);

	return res;
}

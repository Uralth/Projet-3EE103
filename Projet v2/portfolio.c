#include "portfolio.h"

PrtVue InitPrtVue(int dimX, int dimY){
	PrtVue res;

	res.u = createMatrice(dimX, dimY);
	res.v = createMatrice(dimX, dimY);

	return res;
}
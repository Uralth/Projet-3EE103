#ifndef _portfolio_h_
#define _portfolio_h_

	#include "matrice.h"
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>

	/* structure faite pour contenir plusieurs matrices */
	typedef struct PrtVue PrtVue;
	struct PrtVue
	{
		double** u;
		double** v;
	};

    /** Initialisation d'un conteneur pour les vitesses
    * @param Dimension X de l'image
    * @param Dimension Y de l'image
    * @return conteneur de U et V
    */
	PrtVue InitPrtVue(int dimX, int dimY);
#endif

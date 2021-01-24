#include "SpeedCalculator2.h"
#include "portfolio.h"

/** Calcul des vitesses de l'image dans une seule structure
  * @param Gradient X de l'image
  * @param Gradient Y de l'image
  * @param Gradient en temps de l'image
  * @param Dimension X de l'image
  * @param Dimension Y de l'image
  * @param Parametre alpha de ponderation
  * @return Structure de U et V
  */
PrtVue vit(double** GradientX,double** GradientY,double** GradientT,int dimX,int dimY,float alpha){
	int i,j,Condition_arret=0,n=0;
	Umoy u_moy = InitUmoy(dimX,dimY),v_moy = InitUmoy(dimX,dimY);
	PrtVue res=InitPrtVue(dimX,dimY);
	double Ix,Iy,It,moyenne_termes =0.0,moy_t=0.0,limite=1.0/(10*dimX*dimY),diff,denom;
    printf("==============================\nCalcul des vitesses en cours...\n");
    while(Condition_arret==0){
        for (i=0;i<dimX;i++){
            for (j=0;j<dimY;j++){
                Ix = GradientX[i][j];
                Iy = GradientY[i][j];
                It = GradientT[i][j];
                denom = alpha+Ix*Ix+Iy*Iy;
                res.u[i][j] = (u_moy.U_moy)[i][j]-(Ix*(Ix*(u_moy.U_moy)[i][j]+Iy*(v_moy.U_moy)[i][j]+It)/denom);
                res.v[i][j] = (v_moy.U_moy)[i][j]-(Iy*(Ix*(u_moy.U_moy)[i][j]+Iy*(v_moy.U_moy)[i][j]+It)/denom);
            }
        }
        UpdateUmoy(&u_moy,res.u);
        UpdateUmoy(&v_moy,res.v);
        moy_t = calcMoyCase(res.u, dimX, dimY);
        diff = moy_t - moyenne_termes;

        if (diff<0){
            diff = diff*-1;
        }

        if (n==100){
            Condition_arret = 1;
        }
        moyenne_termes = calcMoyCase(res.u, dimX, dimY);
        n++;
	}
	printf("Fin du Calcul\n");
	printf("Limite = %f\n",limite);
	printf("Nombre de tours de boucles effectues : %d\n",n-1);
	printf("Difference moyenne %f\n",calcMoyCase(res.u, dimX, dimY));
	return res;
}

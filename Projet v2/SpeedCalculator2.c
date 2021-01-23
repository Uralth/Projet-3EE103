#include "SpeedCalculator2.h"
#include "portfolio.h"

PrtVue vit(double** GradientX,double** GradientY,double** GradientT,int dimX,int dimY,float alpha){
	/* rajouter la marge d'erreur*/
	int i,j,Condition_arret=0,n=0;
	Umoy u_moy = InitUmoy(dimX,dimY),v_moy = InitUmoy(dimX,dimY);
	PrtVue res=InitPrtVue(dimX,dimY);
	double Ix,Iy,It,moyenne_termes =0.0,moy_t=0.0,limite=1.0/(10*dimX*dimY),diff,denom;
    //printf("est rentr?dans la fonction\n");
    //printf("==============================mat cree:\n");
    //printMatrice(res,dimX,dimY);
    while(Condition_arret==0){
        printf("==============================\n");
        for (i=0;i<dimX;i++){
            for (j=0;j<dimY;j++){
                //printf("==============================\n");
                Ix = GradientX[i][j];
                Iy = GradientY[i][j];
                It = GradientT[i][j];
                denom = alpha+Ix*Ix+Iy*Iy;
                res.u[i][j] = (u_moy.U_moy)[i][j]-(Ix*(Ix*(u_moy.U_moy)[i][j]+Iy*(v_moy.U_moy)[i][j]+It)/denom);
                res.v[i][j] = (v_moy.U_moy)[i][j]-(Iy*(Ix*(u_moy.U_moy)[i][j]+Iy*(v_moy.U_moy)[i][j]+It)/denom);
                //printMatrice(res,dimX,dimY);
                //printf("\n");
                //printf("ca marche l\n");
                //printf("x = %d\n",i);
                //printf("y = %d\n",j);
            }
            //printf("ca marche colonne changee\n");
        }
        printMatrice(res.u,dimX,dimY);
        UpdateUmoy(&u_moy,res.u);
        UpdateUmoy(&v_moy,res.v);
        printf("=umoy=\n");
        printMatrice(u_moy.U_moy,dimX,dimY);
        printf("======\n");
        printf("moyenne termes = %f\n",calcMoyCase(res.u, dimX, dimY));
        printf("moyt = %f\n", moyenne_termes);
        moy_t = calcMoyCase(res.u, dimX, dimY);
        //printf("diff moyenne cases = %f",sqrt( (moyenne_termes-calcMoyCase(res, dimX, dimY))*(moyenne_termes-calcMoyCase(res, dimX, dimY))));
        diff = moy_t - moyenne_termes;

        if (diff<0){
            printf("ntm\n");
            diff = diff*-1;
        }
        printf("diff = %f\n", diff);
        //if(diff<limite){
        //if(n==10){
            //printf("arret");
            //Condition_arret = 1;
        //}
        if (n==400){
            Condition_arret = 1;
        }
        moyenne_termes = calcMoyCase(res.u, dimX, dimY);
        n++;
	}
	printf("limite = %f\n",limite);
	printf("nombre de tours de boucles effectues : %d\n",n-1);
	printf("diff moyenne %f\n",calcMoyCase(res.u, dimX, dimY));
	return res;
}

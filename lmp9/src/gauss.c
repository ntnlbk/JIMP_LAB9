#include "gauss.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		 //printf("from eliminate: \n");
		 int i, j;
		 for (i = 0; i < (mat->c - 1); i++){
		 	double maks = fabs(mat->data[i][i]);
		 	int maksr = i;
		 	for (j = i; j<(mat->c - 1); j++){
		 		if (maks < fabs(mat->data[j+1][i])){
		 			maks = mat->data[j+1][i];
		 			maksr = j+1;
		 			}
		 	}
		 	//printf("W kolumne %d najw. to %g w wiersze %d\n", i, maks, maksr);
		 	if (maksr != i){
		 		//printf("swap wiersz %d i %d\n", i, maksr);
		 		//printToScreen(mat);
		 		double *temp = mat->data[i];
		 		mat->data[i] = mat->data[maksr];
		 		mat->data[maksr] = temp;
		 		//printToScreen(mat);
		 		temp = b->data[i];
		 		b->data[i] = b->data[maksr];
		 		b->data[maksr] = temp;
		 	} 
		 	
		 	double gl = mat->data[i][i];
		 	for(j = i+1; j< mat->c; j++){
		 		double temp = mat->data[j][i] / gl;
		 		int z;
		 		for (z = i; z < mat->c; z++){
		 			mat->data[j][z] = mat->data[j][z] - (temp * mat->data[i][z]);
		 		}
		 		b->data[j][0] = b->data[j][0] - (temp * b->data[i][0]);
		 	}
		 	
		 	
		 }
		//printToScreen(mat);
		//printf("end eliminate: \n");
		return 0;
}




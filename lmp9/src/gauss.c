#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		 printf("from eliminate: \n");
		 int i, j;
		 for (i = 0; i < (mat->c - 1); i++){
		 	double maks = mat->data[i][i];
		 	int maksr = i;
		 	for (j = i; j<(mat->c - 1); j++){
		 		if (maks < mat->data[j+1][i]){
		 			maks = mat->data[j+1][i];
		 			maksr = j+1;
		 			}
		 	}
		 	//printf("W kolumne %d najw. to %g w wiersze %d\n", i, maks, maksr);
		 	if (maksr != i){
		 		printf("swap wiersz %d i %d\n", i, maksr);
		 		printToScreen(mat);
		 		double *temp = mat->data[i];
		 		mat->data[i] = mat->data[maksr];
		 		mat->data[maksr] = temp;
		 		printToScreen(mat);
		 		temp = b->data[i];
		 		b->data[i] = b->data[maksr];
		 		b->data[maksr] = temp;
		 	} else{
		 		printf("swap nie trzeba\n");
		 	}
		 	
		 	
		 	
		 }
		
		printf("end eliminate: \n");
		return 0;
}




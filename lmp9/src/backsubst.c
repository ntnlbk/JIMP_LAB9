#include "backsubst.h"
#include <stdio.h>

int backsubst(Matrix *x, Matrix *A, Matrix *b) {
    int n = A->r;

    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A->data[i][j] * x->data[j][0];
        }
        if (A->data[i][i] == 0) {
            return -1;
        }
        x->data[i][0] = (b->data[i][0] - sum) / A->data[i][i];
    }
    return 0;
}

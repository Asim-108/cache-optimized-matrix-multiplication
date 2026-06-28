#ifndef MATRIX_ALGORITHMS_H
#define MATRIX_ALGORITHMS_H

void multiply_naive(int **A, int **B, int **C, int N);
void multiply_tiled(int **A, int **B, int **C, int N, int TILE_SIZE);

#endif



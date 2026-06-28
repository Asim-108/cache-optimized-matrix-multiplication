#include <stdio.h>   // For reading/printing matrices (printf, scanf)
#include <stdlib.h>  // For dynamic memory allocation (malloc, free)
#include <time.h>    // For generating random matrix values or measuring time
#include "matrix_algorithms.h"

void multiply_naive(int **A, int **B, int **C, int N);
void multiply_tiled(int **A, int **B, int **C, int N, int TILE_SIZE);


void multiply_naive(int **A, int **B, int **C, int N) {

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Naive Matrix multiplication took %f seconds\n", cpu_time_used);
   
    return;
}

void multiply_tiled(int **A, int **B, int **D, int N, int TILE_SIZE) {
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();


    // incrementing i, j, k by TILE_SIZE to increment the tile
    for (int i = 0; i < N; i += TILE_SIZE) {
        for (int j = 0; j < N; j += TILE_SIZE) {
            for (int k = 0; k < N; k += TILE_SIZE) {
                // Determine limits for the current tile
                int i_limit = (i + TILE_SIZE < N) ? i + TILE_SIZE : N;
                int j_limit = (j + TILE_SIZE < N) ? j + TILE_SIZE : N;
                int k_limit = (k + TILE_SIZE < N) ? k + TILE_SIZE : N;

                // matrix multiplication inside of the tile
                for (int i1 = i; i1 < i_limit; i1++) {
                    for (int j1 = j; j1 < j_limit; j1++) {
                        for (int k1 = k; k1 < k_limit; k1++) {
                            D[i1][j1] += A[i1][k1] * B[k1][j1];
                        }
                    }
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiled(Block Size : %d) Matrix multiplication took %f seconds\n", TILE_SIZE, cpu_time_used);

    return;
}
#include <stdio.h>   // For reading/printing matrices (printf, scanf)
#include <stdlib.h>  // For dynamic memory allocation (malloc, free)
#include <time.h>    // For generating random matrix values or measuring time
#include "matrix_algorithms.h"

// #define TILE_SIZE 32


int main() {
    int **A, **B, **C, **D;

    // Declare variables
    int N;          // Size of square matrices
    int TILE_SIZE;

    // Get matrix size from user
    printf("Enter the size of the matrices (N for NxN): ");
    scanf("%d", &N);

    printf("Enter the tile size: ");
    scanf("%d", &TILE_SIZE);

    // Allocate memory for matrices
    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(N * sizeof(int *));
    D = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
        D[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize matrices with random values
    srand(time(NULL));  // Seed random number generator
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;             // Random int between 0 and 99
            B[i][j] = rand() % 100;
        }
    }

    // initialize matrix C and D to 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            D[i][j] = 0;
        }
    }


    multiply_naive(A, B, C, N);


    multiply_tiled(A, B, D, N, TILE_SIZE);

    // Clean up memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}
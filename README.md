# Cache-Optimized Matrix Multiplication

This project implements two different matrix multiplication algorithms—naive and tiled (blocked)—to demonstrate how cache optimization can significantly improve performance.

## Algorithms

### 1. Naive Matrix Multiplication

The standard triple-loop algorithm where the order of loops is:
```
for i
  for j
    for k
      C[i][j] += A[i][k] * B[k][j]
```
**Cache Behavior:** Poor temporal locality. Each access to `B[k][j]` jumps far across memory (stride `N`), causing frequent cache misses.

### 2. Tiled (Blocked) Matrix Multiplication

The matrix is divided into smaller blocks (tiles) of size `TILE_SIZE × TILE_SIZE`. The multiplication is performed within these blocks.

**Cache Behavior:** Excellent temporal locality. By processing a block, the same data in the cache is reused multiple times before moving to the next block, drastically reducing cache misses.

## Performance Comparison

| Feature | Naive | Tiled |
| :--- | :--- | :--- |
| **Cache Efficiency** | Low | High |
| **Access Pattern** | Strided (poor) | Contiguous (good) |
| **Typical Speedup** | Baseline | **2–4× faster** |
| **Memory Access** | Many cache misses | Fewer cache misses |

## How to Compile and Run

**Prerequisites:** GCC C++ Compiler

1.  **Compile:**
    ```bash
    g++ -O3 test.cpp matrix_algorithms.cpp -o program
    ```
    *(Note: The `-O3` flag enables aggressive compiler optimizations, which further highlights the performance difference.)*

2.  **Run:**
    ```bash
    .\program.exe
    ```

## Sample Output

```
Enter the size of the matrices (N for NxN): 500
Enter the tile size: 32
Naive Matrix multiplication took 0.065000 seconds
Tiled(Block Size : 32) Matrix multiplication took 0.032000 seconds
```

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return false;

    int row = 0;
    int col = matrixColSize[0] - 1;  // start at top-right

    while (row < matrixSize && col >= 0) {
        int current = matrix[row][col];

        if (current == target) {
            return true;
        }
        else if (current > target) {
            col--;      // move left
        }
        else {
            row++;      // move down
        }
    }

    return false;
}


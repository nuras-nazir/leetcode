int count(int** matrix, int n, int mid) {

    int i = n - 1;
    int j = 0;
    int c = 0;

    while(i >= 0 && j < n) {

        if(matrix[i][j] <= mid) {

            c += i + 1;
            j++;
        }
        else
            i--;
    }

    return c;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {

    int low = matrix[0][0];
    int high = matrix[matrixSize-1][matrixSize-1];

    while(low < high) {

        int mid = low + (high - low) / 2;

        if(count(matrix, matrixSize, mid) < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

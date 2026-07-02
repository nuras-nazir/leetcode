void backtrack(int* nums, int numsSize, int index,
               int* path, int pathSize,
               int*** result, int* returnSize, int** returnColumnSizes) {

    (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        (*result)[*returnSize][i] = path[i];
    }
    (*returnColumnSizes)[*returnSize] = pathSize;
    (*returnSize)++;

    for (int i = index; i < numsSize; i++) {
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int total = 1 << numsSize;

    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, path, 0,
              &result, returnSize, returnColumnSizes);

    free(path);

    return result;
}

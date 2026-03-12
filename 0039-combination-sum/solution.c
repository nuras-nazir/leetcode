/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target, int start,
         int* temp, int tempSize,
         int*** result, int* returnSize, int** returnColumnSizes) {

    if(target == 0) {
        (*result)[*returnSize] = malloc(tempSize * sizeof(int));
        for(int i=0;i<tempSize;i++)
            (*result)[*returnSize][i] = temp[i];

        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for(int i=start;i<candidatesSize;i++) {

        if(candidates[i] > target)
            continue;

        temp[tempSize] = candidates[i];

        dfs(candidates, candidatesSize,
            target - candidates[i],
            i, temp, tempSize+1,
            result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    int** result = malloc(150 * sizeof(int*));
    *returnColumnSizes = malloc(150 * sizeof(int));

    int temp[100];

    *returnSize = 0;

    dfs(candidates, candidatesSize, target, 0,
        temp, 0, &result, returnSize, returnColumnSizes);

    return result;
}

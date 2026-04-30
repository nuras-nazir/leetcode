#include <stdlib.h>

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int* level = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;

        leftToRight = !leftToRight; // flip direction
    }

    return result;
}

#include <stdlib.h>

typedef struct {
    struct TreeNode* node;
    unsigned long long index;
} Pair;

int widthOfBinaryTree(struct TreeNode* root) {
    if (!root) return 0;

    Pair queue[3000];
    int front = 0, rear = 0;

    queue[rear++] = (Pair){root, 0};
    int maxWidth = 0;

    while (front < rear) {
        int size = rear - front;

        unsigned long long start = queue[front].index;
        unsigned long long end = start;

        for (int i = 0; i < size; i++) {
            Pair curr = queue[front++];
            
            unsigned long long idx = curr.index - start; // normalize
            end = idx;

            if (curr.node->left)
                queue[rear++] = (Pair){curr.node->left, 2 * idx};

            if (curr.node->right)
                queue[rear++] = (Pair){curr.node->right, 2 * idx + 1};
        }

        int width = end + 1;
        if (width > maxWidth) maxWidth = width;
    }

    return maxWidth;
}

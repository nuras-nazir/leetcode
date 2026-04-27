/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <limits.h>

int maxSum;

int dfs(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    // Ignore negative paths
    if (left < 0) left = 0;
    if (right < 0) right = 0;

    // Case 1: full path through node
    int current = left + right + root->val;

    if (current > maxSum) maxSum = current;

    // Case 2: return one side to parent
    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    maxSum = INT_MIN;
    dfs(root);
    return maxSum;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;

    // If we find p or q, return it
    if (root == p || root == q) return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides returned non-null → this is LCA
    if (left != NULL && right != NULL) return root;

    // Otherwise return the non-null side
    return (left != NULL) ? left : right;
}

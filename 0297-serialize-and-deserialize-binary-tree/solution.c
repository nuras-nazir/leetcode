/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helperSerialize(struct TreeNode* root, char* str) {

    if(root == NULL) {
        strcat(str, "N,");
        return;
    }

    char temp[20];

    sprintf(temp, "%d,", root->val);

    strcat(str, temp);

    helperSerialize(root->left, str);
    helperSerialize(root->right, str);
}

char* serialize(struct TreeNode* root) {

    char* str = (char*)malloc(100000);

    str[0] = '\0';

    helperSerialize(root, str);

    return str;
}

struct TreeNode* helperDeserialize(char** data) {

    if(**data == 'N') {

        (*data) += 2;

        return NULL;
    }

    int sign = 1;

    if(**data == '-') {
        sign = -1;
        (*data)++;
    }

    int num = 0;

    while(**data != ',') {

        num = num * 10 + (**data - '0');

        (*data)++;
    }

    num *= sign;

    (*data)++;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = num;

    root->left = helperDeserialize(data);

    root->right = helperDeserialize(data);

    return root;
}

struct TreeNode* deserialize(char* data) {

    return helperDeserialize(&data);
}

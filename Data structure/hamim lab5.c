#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* stack[1000];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        printf("%d ", node->val);
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right = NULL;
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    printf("Preorder Traversal of Binary Tree: ");
    preorderTraversal(root);
    printf("\n");

    free(root->left);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
#include <TreeNode.h>


// Function to create a new TreeNode
struct TreeNode* createTNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to construct a binary tree
struct TreeNode* constructBinaryTree() {
    struct TreeNode* root = createTNode(1);
    root->left = createTNode(3);
    root->right = createTNode(5);
    root->left->left = createTNode(1);
    root->left->right = createTNode(2);
    root->right->left = createTNode(6);
    root->right->right = createTNode(7);
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory occupied by the binary tree
void freeBinaryTree(struct TreeNode* root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

#ifndef TREENODE_H_
#define TREENODE_H_

#include <stdio.h>
#include <stdlib.h>

// Definition of struct TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new TreeNode
struct TreeNode* createTNode(int value);
// Function to construct a binary tree
struct TreeNode* constructBinaryTree();

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root);

// Function to free the memory occupied by the binary tree
void freeBinaryTree(struct TreeNode* root);

#endif

//AIM : WAP to perform tree creation and traversal.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}


//THEORY

/*
    Theory of Binary Tree and Traversals:

    A Binary Tree is a tree data structure where each node has at most two children, referred to as the left and right child.
    
    1. Preorder Traversal:
       - In this traversal, the root node is visited first, followed by the left subtree and then the right subtree.
       - The order of traversal is: Root -> Left -> Right.
       - Time Complexity: O(n), where n is the number of nodes.
    
    2. Inorder Traversal:
       - In this traversal, the left subtree is visited first, followed by the root node and then the right subtree.
       - The order of traversal is: Left -> Root -> Right.
       - Time Complexity: O(n), where n is the number of nodes.
    
    3. Postorder Traversal:
       - In this traversal, the left subtree is visited first, followed by the right subtree and then the root node.
       - The order of traversal is: Left -> Right -> Root.
       - Time Complexity: O(n), where n is the number of nodes.
    
    These traversal techniques are fundamental for processing and manipulating data in binary trees. They can be used in various applications, such as:
    - Expression parsing.
    - Searching in binary search trees (BSTs).
    - Tree-based algorithms like depth-first search (DFS).
*/
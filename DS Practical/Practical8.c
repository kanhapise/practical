//WAP to perform search tree creation and searching .


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

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }

    if (value == root->data) {
        return 1; 
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, searchValue;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the value to search in the BST: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("Element %d found in the tree.\n", searchValue);
    } else {
        printf("Element %d not found in the tree.\n", searchValue);
    }

    return 0;
}


//Theory :
/*
    Theory of Binary Search Tree (BST) and Searching:

    A Binary Search Tree (BST) is a binary tree in which for each node:
    - The left subtree contains only nodes with values less than the node's value.
    - The right subtree contains only nodes with values greater than the node's value.
    The tree follows the property where for every node, values in the left subtree are smaller, and values in the right subtree are larger.

    1. Insertion in BST:
       - Insertion starts at the root and proceeds by comparing the value to be inserted with the current node's value.
       - If the value is smaller, we move to the left subtree, otherwise, we move to the right subtree.
       - This process continues until we find an empty position (NULL) to insert the new node.
       - Insertion is recursive, and the tree grows downwards as new nodes are added.

    Algorithm for Insertion:
    - If the tree is empty, create a new node with the value.
    - Otherwise, compare the value to be inserted with the root node.
    - If the value is less, insert it in the left subtree.
    - If the value is greater, insert it in the right subtree.

    2. Searching in BST:
       - Searching for a value in a BST is efficient due to the property of the tree.
       - Starting at the root node, we compare the search value with the current node's value.
       - If the value is smaller, we search the left subtree; if larger, we search the right subtree.
       - The search continues until either the value is found or the subtree becomes NULL, indicating the value is not in the tree.

    Algorithm for Searching:
    - If the current node is NULL, return failure (value not found).
    - If the value matches the current node's data, return success (value found).
    - If the value is smaller, search the left subtree.
    - If the value is larger, search the right subtree.

    3. Time Complexity:
       - The average time complexity for both insertion and searching in a BST is O(log n), where n is the number of nodes.
       - However, in the worst case (when the tree is unbalanced), the time complexity can degrade to O(n).
       - Balanced trees (such as AVL or Red-Black trees) provide better performance by ensuring the height remains logarithmic.

    BST is a fundamental data structure widely used in applications such as:
    - Searching for elements efficiently.
    - Sorting elements by in-order traversal.
    - Implementing associative arrays and maps.
*/

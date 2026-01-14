#include <stdio.h>
#include <stdlib.h>
// Define structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a node into the Binary Search Tree
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
// Inorder Traversal (Left, Root, Right)
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
// Preorder Traversal (Root, Left, Right)
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
// Postorder Traversal (Left, Right, Root)
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct Node* root = NULL;

    // Insert nodes into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 60);
    root = insert(root, 80);
    // Perform traversals
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

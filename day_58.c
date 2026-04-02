// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current node from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find position in inorder
    int pos = search(inorder, start, end, curr);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
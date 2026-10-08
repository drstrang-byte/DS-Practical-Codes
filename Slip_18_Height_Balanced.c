#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node *root) {
    int lh, rh;

    if(root == NULL)
        return 0;

    lh = height(root->left);
    rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node *root) {
    int lh, rh;

    if(root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh - rh) > 1)
        return 0;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node *root;

    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    printf("Height = %d\n", height(root));

    if(isBalanced(root))
        printf("Tree is Balanced\n");
    else
        printf("Tree is Not Balanced\n");

    return 0;
}
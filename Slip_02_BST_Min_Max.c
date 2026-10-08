#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node *root, int value) {
    if(root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int findMin(struct Node *root) {
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node *root) {
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node *root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}
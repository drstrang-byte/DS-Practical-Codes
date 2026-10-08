#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if(root == NULL)
        return create(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct Node* copy(struct Node *root) {
    struct Node *newRoot;

    if(root == NULL)
        return NULL;

    newRoot = create(root->data);
    newRoot->left = copy(root->left);
    newRoot->right = copy(root->right);

    return newRoot;
}

int compare(struct Node *t1, struct Node *t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    return (t1->data == t2->data &&
            compare(t1->left, t2->left) &&
            compare(t1->right, t2->right));
}

int main() {
    struct Node *root = NULL;
    struct Node *root2;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    root2 = copy(root);

    if(compare(root, root2))
        printf("Trees are Equal\n");
    else
        printf("Trees are Not Equal\n");

    return 0;
}
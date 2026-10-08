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

struct Node* insert(struct Node *root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void levelOrder(struct Node *root) {
    struct Node *queue[100];
    int front = 0, rear = 0;
    int level = 1, count, i;

    if(root == NULL)
        return;

    queue[rear++] = root;

    while(front < rear) {
        count = rear - front;

        printf("Level %d: ", level);

        for(i = 0; i < count; i++) {
            struct Node *temp = queue[front++];

            printf("%d ", temp->data);

            if(temp->left != NULL)
                queue[rear++] = temp->left;

            if(temp->right != NULL)
                queue[rear++] = temp->right;
        }

        printf(" Count = %d\n", count);
        level++;
    }

    printf("Total levels = %d\n", level - 1);
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

    levelOrder(root);

    return 0;
}
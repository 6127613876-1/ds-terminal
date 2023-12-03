#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int height(struct node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int isBalanced(struct node* root) {
    if (root == NULL)
        return 1; 

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right)) {
        return 1;
    }

    return 0;
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* create() {
    int x;
    printf("Enter node : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    struct node* root = createNode(x);
    root->data = x;
    printf("Left child of %d ", x);
    root->left = create();
    printf("Right child of %d ", x);
    root->right = create();
    return root;
}

int main() {
    struct node* root = create();
    if (isBalanced(root)) {
        printf("The tree is height-balanced.\n");
    } else {
        printf("The tree is not height-balanced.\n");
    }
    return 0;
}

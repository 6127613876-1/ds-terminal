
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int maxValue(struct node* node)
{
    if (node == NULL) {
        return 0;
    }
 
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
 
    int value = 0;
    if (leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value < node->data) {
        value = node->data;
    }
 
    return value;
}
 
int minValue(struct node* node)
{
    if (node == NULL) {
        return 1000000000;
    }
 
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    int value = 0;
    if (leftMax < rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value > node->data) {
        value = node->data;
    }
 
    return value;
}

int isBST(struct node* node)
{
    if (node == NULL)
        return 1;
    if (node->left != NULL
        && maxValue(node->left) > node->data)
        return 0;
     if (node->right != NULL
        && minValue(node->right) < node->data)
        return 0;
    if (!isBST(node->left) || !isBST(node->right))
        return 0;
 
    return 1;
}
 
int main()
{
    int x,i;
    printf("Enter the value of root:");
    scanf("%d",&x);
    struct node* root = newNode(x);
    do
    {
        int d;
        printf("Enter the value:");
        scanf("%d",&d);
        root = insert(root,d);
    }while(i==1);
    if (isBST(root))
        printf("yes");
    else
        printf("No");
 
    getchar();
    return 0;
}

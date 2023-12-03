#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *newnode, int x)
{
    if (newnode == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else
    {
        if (x < newnode->data)
        {
            newnode->left = insert(newnode->left, x);
        }
        else
        {
            newnode->right = insert(newnode->right, x);
        }
    }
    return newnode;
}
int rangeSumBST(struct node *root, int low, int high)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum = 0;

    if (root->data >= low && root->data <= high)
    {
        sum += root->data;
    }

    if (root->data > low)
    {
        sum += rangeSumBST(root->left, low, high);
    }

    if (root->data < high)
    {
        sum += rangeSumBST(root->right, low, high);
    }

    return sum;
}
void main()
{
    struct node *root;
    int i = 1;
    int x, l, h;
    root = NULL;
    while (i == 1)
    {
        printf("enter element:");
        scanf("%d", &x);
        root = insert(root, x);
        printf("enter 1 to continue..");
        scanf("%d", &i);
    }
    printf("low:");
    scanf("%d", &l);
    printf("high:");
    scanf("%d", &h);
    printf("sum:%d", rangeSumBST(root, l, h));
}
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter node : ");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Left child of %d ",x);
    newnode->left=create();
    printf("Right child of %d ",x);
    newnode->right=create();
    return newnode;
}
int tree_height(struct node* root) 
{
    if (!root)
        return 0;
    else 
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
void main()
{
    struct node* root;
    int height;
    printf("enter -1 incase you no need to insert a node\n");
    root=create();
    height = tree_height(root);
    printf("Height of the Binary Tree: %d\n", height);
}

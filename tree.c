#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
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
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


struct node *search(struct node *root, int key){
    if (root==NULL || root->data==key)
        return root;
    if (search(root->left,key)==NULL)
        return search(root->right,key);
    return search(root->left,key);
};

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void leftviewut(struct node *root,int level,int *maxlevel)
{
    if (root==NULL)
    {
        return;
    }
    if (*maxlevel<level)
    {
        printf("%d",root->data);
        *maxlevel=level;
    }
    leftviewut(root->left,level+1,maxlevel);
    leftviewut(root->right,level+1,maxlevel);
}

void leftview(struct node *root)
{
    int maxlevel=0;
    printf("Left view of the BST: ");
    leftviewut(root, 1, &maxlevel);
    printf("\n");
}

bool isbstut(struct node *root,int min,int max)
{
    if (root==NULL)
    {
        return true;
    }

    if (root->data<min || root->data>max)
    {
        return false;
    }
    
    return (isbstut(root->left,min,root->data-1) && isbstut(root->right,root->data-1,max));
}

void topView( struct node *root) {
        if (root!=NULL) {
            printf("%d ",root->data);
            topView(root->right);
        }
}

bool isbst(struct node *root)
{
    return isbstut(root,INT_MIN,INT_MAX);
}

void main()
{
    struct node* root;
    printf("enter -1 incase you no need to insert a node\n");
    root=create();
    printf("pre-order : ");
    preorder(root);
    printf("\nin-order : ");
    inorder(root);
    printf("\npost-order : ");
    postorder(root);
    if(search(root,25))
    {
        printf("The value is found");
    }
    else
    {
        printf("The value is not found");
    }
    if (isbst(root))
    {
        printf("BST");
    }
    else
    {
        printf("Not BST");
    }
    printf("\n");
    leftview(root);
    printf("\nTop view");
    topView(root);
}

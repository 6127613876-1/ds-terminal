#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *newnode,int data)
{
    if(newnode==NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
    }
    else
    {
        if(data<newnode->data)
        {
            newnode->left=insert(newnode->left,data);
        }
        else
        {
            newnode->right=insert(newnode->right,data);
        }   
    }
    return newnode;
};

struct node *search(struct node *root,int key)
{
    if (root==NULL || root->data == key)
    {
        return root;
    }

    if (key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}

int fllst(struct node *root)
{
    if (root->right==NULL)
    {
        return root->data;
    }
    return fllst(root->right);
    
}

int rangesum(struct node *root,int low,int high)
{
    if (root==NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->data>=low && root->data<=high)
    {
        sum+=root->data;
    }
    
    if (root->data>low)
    {
        sum+=rangesum(root->left,low,high);
    }
    
    if (root->data<high)
    {
        sum+=rangesum(root->right,low,high);
    }
    
    return sum;
}

struct node *delete(struct node *root,int key)
{
    if (root==NULL)
    {
        return root;
    }
    if (key<root->data)
    {
        root->left=delete(root->left,key);
    }
    else if (key>root->data)
    {
        root->right=delete(root->right,key);
    }
    else
    {
        if (root->left==NULL)
        {
            struct node *temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        root->data=fllst(root->left);
        root->left=delete(root->left,root->data);
    }
    return root;
    
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void main()
{
    int i,j,x,choice;
    struct node *root;
    root=NULL;
    do
    {
        printf("\n1)insert\n2)RangeSum\n3)search\n4)delete\n5)print\n6)exit");
        printf("Enter the choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the element");
            scanf("%d",&x);
            root = insert(root,x);
            break;
        }
        case 2:
        {
            int low,high;
            printf("enter low");
            scanf("%d",&low);
            printf("enter high");
            scanf("%d",&high);
            printf("sum=%d",rangesum(root,low,high));
            break;
        }
        case 3:
        {
            printf("Enter the key");
            int key;
            scanf("%d",&key);
            if (search(root, key))
                    printf("Element found in the BST.\n");
                else
                    printf("Element not found in the BST.\n");
                break;
        }
        case 4:
        {
            int key;
            printf("Enter element to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
        }
        case 5:
        {
            printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
        }
        case 6:
        {
            exit(0);
        }
        default:
            break;
        }
    } while (choice!=6);
    
}
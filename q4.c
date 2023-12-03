#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *newnode, int data)
{
    if (newnode == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else
    {
        if (data < newnode->data)
        {
            newnode->left = insert(newnode->left, data);
        }
        else
        {
            newnode->right = insert(newnode->right, data);
        }
    }
    return newnode;
}

struct node *fllst(struct node *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return fllst(root->right);
}

struct node *search(struct node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        root->data = fllst(root->left);
        root->left = delete (root->left, root->data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void main()
{
    int i, j;
    struct node *root = NULL;
    int choice;
    do
    {
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the element:");
            int data;
            scanf("%d", &data);
            root = insert(root, data);
            break;
        }
        case 2:
        {
            int data;
            printf("Enter the data:");
            scanf("%d", &data);
            if (search(root, data))
            {
                printf("Ele is present");
            }
            else
            {
                printf("Ele is not present");
            }
            break;
        }
        case 3:
        {
            int key;
            printf("Enter the data:");
            scanf("%d",&key);
            root = delete (root, key);
            break;
        }
        case 4:
        {
            inorderTraversal(root);
        }
        default:
            break;
        }
    } while (choice != 5);
}
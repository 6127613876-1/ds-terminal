#include <stdio.h>
#define t 10
int h[t];


void insert(int x)
{
    int y =x%t;
    int j=0;
    int u=y;
    while (h[y]!=0)
    {
        y=(u+j)%t;
        j++;
    }
    h[y]=x;
}

void search(int x)
{
    int y =x%t;
    int j=0;
    int u=y;
    while (h[y]!=x)
    {
        y=(u+j)%t;
        j++;
    }
    printf("The position is %d",y);
}

void target(int target)
{
    for(int i=0;i<t;i++)
    {
        int num1=h[i];
        int num2=target-num1;

        int j=0;
        int u = num2%t;
        int y=u;
        while (h[y]!=num2 && h[y]!=0)
        {
            y=(u+j)%t;
            j++;
        }
        if (h[y]==num2)
        {
            printf("The pairs of %d + %d = %d\n",num1,num2,target);
            return;
        }
    }
    printf("The pairs is not found\n");
}

void main()
{
    int i,j;
    int arr[5]={1,55,4,44,7555};
    int choice;
    int n =sizeof(arr)/sizeof(arr[0]);
    printf("The size id %d\n",n);
    do
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            for(i=0;i<n;i++)
            {
                insert(arr[i]);
            }
            break;
        }
        case 2:
        {
            int data;
            printf("Enter the data:");
            scanf("%d",&data);
            search(data);
            break;
        }
        case 3:
        {
            for(int i=0;i<t;i++)
            {
                printf("%d %d \n",i,h[i]);
            }
            break;
        }
        case 4:
        {
            int tar;
            scanf("%d",&tar);
            target(tar);
            break;
        }
        default:
            break;
        }
    } while (choice!=5);
}

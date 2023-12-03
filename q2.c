#include <stdio.h>

int q[10];
int front =-1;
int rear =-1;

int isempty(){return (front==-1 && rear ==-1);}
int isfull(){return ((rear+1)%10==front);}

int enqueue(int val)
{
    if (isfull())
    {
        /* code */printf("Queue is full");
        return;
    }
    if(isempty())
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%10;
    }
    q[rear]=val;
}

int dequeue()
{
    if(isempty())
    {
        printf("Queue is empty");
        return -1;
    }
    int removed = q[front];
    if (rear==front)
    {
        rear=front=-1;
    }
    else
    {
        front=(front+1)%10;
    }
    return removed;
}

int jo(int m)
{
    int i;
    while (!isempty())
    {
        for ( i = 1; i < m; i++)
        {
            int frontvalue=dequeue();
            enqueue(frontvalue);
        }
        int eliminated = dequeue();
        printf("The person %d is eliminated.\n",eliminated);
        while (isempty())
        {
            return eliminated;
        }
    }
    return -1;   
}
void display()
{
    for (int i = front; i < rear+1; i++)
    {
        printf("%d ", q[i]);
    }
}
int main()
{
    int n,m;
    n=5;
    m=3;
    int choice;
    printf("Choice");
    
    do
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter the data");
            scanf("%d",&data);
            enqueue(data);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            int pos = jo(m);
            printf("The position is %d",pos);
            break;
        }
        default:
            break;
        }
    } while (choice!=5);
}
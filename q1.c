#include <stdio.h>

void main()
{
    int i,j,arr[5]={10,4,557,3,45};
    int n = sizeof(arr)/sizeof(arr[5]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
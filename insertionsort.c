#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int * b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void insertionsort(int *,int);
int main(void)
{
    int *arr,i,n;
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nOriginal Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    insertionsort(arr,n);
    printf("\nInsertion Sorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
void insertionsort(int *a,int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        j=i-1;
        t=a[i];
        while(j>=0 && a[j]>t)
        {
                a[j+1]=a[j];
                j--;
        }
        a[j+1]=t;
    }
}

#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int * b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void selectionsort(int *,int);
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

    selectionsort(arr,n);
    printf("\nSelection Sorted Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
void selectionsort(int *a,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int * b);
void insertionsort(int*,int);
int binarysearch(int *,int,int,int);
int main(void)
{
    int *arr,i,n,k,kidx;
    printf("Enter number of elements : ");
    scanf("%d",&n);

    arr=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    insertionsort(arr,n);
    printf("\nSorted Original Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\nEnter number : ");
    scanf("%d",&k);

    kidx=binarysearch(arr,0,n,k);

    if(kidx!=-1)
        printf("Found at array[%d]",kidx);
    else printf("Not Found");

    return 0;
}
void swap(int *a,int * b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
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
int binarysearch(int *arr,int a,int b ,int k)
{
    int i;
    i=(a+b)/2;
    if(k>arr[b-1] || k<arr[0] || a==b)
        return -1;
    if (arr[i]==k)
        return i;
    else if(arr[i]>k)
        return binarysearch(arr,a,i-1,k);
    else if(arr[i]<k)
        return binarysearch(arr,i+1,b,k);

}

#include<stdio.h>
void swapint(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int *const,const int n);
main()
{
    int n,i,j,A[100];
    printf("Enter n : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    printf("\nOriginal Array : \n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    bubblesort(A,n);

    printf("\nSorted(Bubble) Array :\n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
void bubblesort(int * const A,const int n)
{
    int i,j,flag=1;
    for(i=0;i<n-1 && flag==1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            flag=0;
            if(A[j]>A[j+1])
            {
                swapint(&A[j],&A[j+1]);
                flag=1;
            }
        }
    }
}

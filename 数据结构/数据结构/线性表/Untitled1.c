#include<stdio.h>

int Max(int a[], int n)
{
    int i;
    int CurMax = a[0];
    for(i=1; i<n; i++)
    {
        if(a[i] > CurMax)
        {
            CurMax = a[i];
        }
    }
    return CurMax;
}

void main()
{
    int a[10] ={0,1,2,3,4,5,6,7,8,9};
    printf("%d",Max(a, 10));
}

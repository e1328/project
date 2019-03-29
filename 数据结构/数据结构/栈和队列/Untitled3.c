#include<stdio.h>

void main()
{
    int n,i,j,k,c=1;
    scanf("%d",&n);
    int a[n+1][n+1];
    for(k=1;k<=(n+1)/2;k++)
    {
        for(i=k;i<=n-k;i++)
        {
            a[i][n-k+1] = c;
            c++;
        }
        for(i=n-k+1;i>=k+1;i--)
        {
            a[n-k+1][i] = c;
            c++;
        }
        for(i=n-k+1;i>=k+1;i--)
        {
            a[i][k] = c;
            c++;
        }
        for(i=k;i<=n-k;i++)
        {
            a[k][i] = c;
            c++;
        }
    }
    if(n%2!=0)
    {
        a[(n+1)/2][(n+1)/2] = n*n;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

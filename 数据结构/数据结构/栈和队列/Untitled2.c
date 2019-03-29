#include<stdio.h>

void main()
{
    int i,j,n,x,y,c;
    while(scanf("%d",&n)!=EOF)
    {
        c = 1;
        int a[n+1][n+1];
        for(i=1;i<=n;i++)
        {
            x = i,y = 1;
            while(x>=1)
            {
                a[x][y] = c;
                c++;
                x--;
                y++;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n-i+1;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][n-i+1]);
        }
    }
}

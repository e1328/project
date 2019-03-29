#include <stdio.h>
#include <stdlib.h>
main()
{int x,y,n,num,round,count=1;  int a[10][10];
 scanf("%d",&n);
 if(1==n)
  {a[0][0]=count;}
 else
  {for(round=1;round<=n;round++)
      {for(y=0;y<round;y++)
         {a[round-1-y][y]=count;
          count++;
          }
       }
   for(;round<=2*n-1;round++)
     {for(y=round-n;y<n;y++)
        {a[round-1-y][y]=count;
         count++;
        }
      }
for(x=0;x<n;x++)
    {for(y=0;y<n-x;y++)
      printf("%3d",a[x][y]);
     printf("\n");
     }


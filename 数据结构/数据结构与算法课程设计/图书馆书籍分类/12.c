#include<stdio.h>
int main()
{
    int a[10],i,s,k;
    char c[1000000];
    while(gets(c)!=NULL)
    {
        s=0;
        i=0;
        while(*(c+i))
        {
            s=s+(*(c+i)-'0');
            i++;
        }
        i=0;
        while(s)
        {
            *(a+i)=s%10;
            s=s/10;
            i++;
        }
        for(k=i-1;k>=0;k--)
            switch(*(a+k))
            {
              case 0:printf("zero ");break;
              case 1:printf("one ");break;
              case 2:printf("two ");break;
              case 3:printf("three ");break;
              case 4:printf("four ");break;
              case 5:printf("five ");break;
              case 6:printf("six ");break;
              case 7:printf("seven ");break;
              case 8:printf("eight ");break;
              case 9:printf("nine ");break;
            }
        printf("\n");
    }
    return 0;
}

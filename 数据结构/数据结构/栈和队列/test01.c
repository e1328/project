#include<stdio.h>
int f[1000];
int main()
{
    char a[1000];
    int i,j;
    gets(a);
    for(i=0;i<strlen(a);i++)
        if(i%2==0)    f[a[i]]++;
        else f[a[i]]+=2;
    for(i=0;i<1000;i++)
        if(f[i]==1) printf("%c",i);
    for(i=999;i>=0;i--)
        if(f[i]==2) printf("%c",i);
    return 0;
}


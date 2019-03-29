#include<stdio.h>
#include<string.h>

void main()
{
    FILE *fp;
    char str[128];
    if((fp=fopen("test.txt","w"))==NULL)
    {
        printf("cannot open file!");
        exit(0);
    }
    while((strlen(gets(str)))!=0)
    {
        fputs(str,fp);
        fputs("\n",fp);
    }
    fclose(fp);
}

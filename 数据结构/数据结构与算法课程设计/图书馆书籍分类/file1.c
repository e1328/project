#include<stdio.h>

void main()
{
    char ch;
    FILE *fp;
    int i;
    if((fp=fopen("hello.txt","r"))==NULL)
    {
        printf("not open");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

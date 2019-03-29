#include<stdio.h>

void main()
{
    FILE *fp;
    char ch;
    if((fp=fopen("test.txt","w"))==NULL)
    {
        printf("cannot open file!\n");
        exit(0);
    }
    while((ch=fgetchar())!='\n')
        fputc(ch,fp);
    fclose(fp);
}

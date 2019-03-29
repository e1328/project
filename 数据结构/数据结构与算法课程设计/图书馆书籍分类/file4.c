#include<stdio.h>
#include<string.h>

void main()
{
    FILE *fp1,*fp2;
    char str[128];
    if((fp1=fopen("test1.txt","r"))==NULL)
    {
        printf("cannot open file1!");
        exit(0);
    }
    if((fp2=fopen("test2.txt","r"))==NULL)
    {
        printf("cannot open file2!");
        exit(0);
    }
    while((strlen(fgets(str,128,fp1)))>0)
    {
        fputs(str,fp2);
        printf("%s",str);
    }
    fclose(fp1);
    fclose(fp2);
}

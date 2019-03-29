#include<stdio.h>
#include<string.h>
void kongge(char a[])
{
	int i,j,b[2000],z=0;
	for(i=0;a[i];i++)
	if(a[i]!=' ')
	break;
	for(;a[i];i++)
	{
		if(a[i]==' ')
		{
		if(a[i+1]!=' ')
			b[z++]=a[i];
	    }
	    else
	    b[z++]=a[i];
	}
	for(i=0;i<z;i++)
	a[i]=b[i];
	a[i]='\0';
	for(z--;z>=0;z--)
	if(a[z]==' ')
	a[z]='\0';
	else
	if(a[z]!=' ')
	break;
}

void daxie(char a[])
{

	int i;
	if(a[0]>='a'&&a[0]<='z')
	a[0]=a[0]-32;
	for(i=1;a[i];i++)
	{
		if(a[i]==' ')
		{
			if(a[i+1]>='a'&&a[i+1]<='z')
			a[i+1]-=32;
		}
	}
}

void xiahuaxian(char a[])
{
	int i,b[2000],z=0;
	if(a[0]>='0'&&a[0]<='9')
	for(i=0;a[i];i++)
	{
		if(!(a[i]>='0'&&a[i]<='9')&&a[i]!=' ')
		{b[z++]='_';break;}
		else
		if(!(a[i]>='0'&&a[i]<='9')&&a[i]==' ')
		{b[z++]=a[i];break;}
		b[z++]=a[i];
	}
	for(;a[i];i++)
	{
		if(a[i]==' ')
		{
			if(a[i+1]>='0'&&a[i+1]<='9')
			{
				b[z++]=a[i++];
				for(;a[i];i++)
				{
					if(!(a[i]>='0'&&a[i]<='9')&&a[i]!=' '&&a[i]!='\0')
					{b[z++]='_';i--;break;}
					if(!(a[i]>='0'&&a[i]<='9')&&a[i]==' ')
					{i--;break;}
					b[z++]=a[i];
				}
			}
			else
			b[z++]=a[i];
		}
		else
	{      if(a[i]>='0'&&a[i]<='9')
		{
			b[z++]='_';
			for(;a[i];i++)
			{
				if(!(a[i]>='0'&&a[i]<='9')&&a[i]!=' '&&a[i]!='\0')
				{b[z++]='_';i--;break;}
				if(!(a[i]>='0'&&a[i]<='9')&&a[i]==' ')
				{i--;break;}
				b[z++]=a[i];
			}
		}
		else
		b[z++]=a[i];
    }
	}
	for(i=0;b[i];i++)
	a[i]=b[i];
	a[i]='\0';
}

main()
{
	char a[2000];
	while(gets(a)!=NULL)
	{
		int i;
		kongge(a);
		daxie(a);
        xiahuaxian(a);
		puts(a);
		for(i=0;i<2000;i++)
		a[i]='\0';
	}
}

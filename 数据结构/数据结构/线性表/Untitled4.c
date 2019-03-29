#include<stdio.h>
#include<windows.h>
typedef struct Position
{
    int x;
    int y;
}Position, *LPosition;
void main()
{
    Position p1;
    LPosition lp1 = &p1;
    p1.x = 1;
    p1.y = 2;
    int a = *((int*)lp1);
    int b = *(((int*)lp1)+1);
    printf("%d %d",a,b);
    system("pause");
}

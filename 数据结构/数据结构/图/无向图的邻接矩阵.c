#include<stdio.h>
#include<stdlib.h>

typedef char vertexType;
typedef int edgeType;
typedef struct GraphMatrix
{
    int vertexNumber;
    int edgeNumber;
    vertexType *vertex;
    edgeType **edge;
}GraphMatrix;

void GraphMatrix_create(GraphMatrix *g)
{
    int i,j,k;
    printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
    scanf("%d %d",&g->vertexNumber,&g->edgeNumber);
    g->vertex = (vertexType*)malloc(g->vertexNumber*sizeof(vertexType));
    g->edge = (edgeType**)malloc(g->vertexNumber*sizeof(edgeType));
    for(i=0;i<g->vertexNumber;i++) {
        g->edge[i] = (edgeType*)malloc(g->vertexNumber*sizeof(edgeType));
    }
    for(i=0;i<g->vertexNumber;i++) {
        for(j=0;j<g->vertexNumber;j++) {
            g->edge[i][j] = 0;
        }
    }
    for(k=0;k<g->edgeNumber;k++) {
        printf("请输入边(vi,vj)的下标,i和j,用空格隔开:");
        scanf("%d %d",&i,&j);
        g->edge[i][j] = 1;
        g->edge[j][i] = 1;
    }
    printf("Your graph matrix is :\n");
    for(i=0;i<g->vertexNumber;i++) {
        for(j=0;j<g->vertexNumber;j++) {
            printf("%d\t",g->edge[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    GraphMatrix *gm;
    gm = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    GraphMatrix_create(gm);
}

#include<stdio.h>
#include<stdlib.h>

typedef char vertexType;
typedef struct ListEdgeNode
{
    int index;
    struct ListEdgeNode *next;
}ListEdgeNode;

typedef struct ListVertexNode
{
    vertexType vertex;
    ListEdgeNode *firstEdge;
}ListVertexNode;

typedef struct GraphList
{
    int vertexNumber;
    int edgeNumber;
    ListVertexNode *vertex;
}GraphList;

void GraphList_create(GraphList *g)
{
    int i,j,k;
    printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
    scanf("%d %d",&g->vertexNumber,&g->edgeNumber);
    g->vertex = (ListVertexNode*)malloc(g->vertexNumber*sizeof(ListVertexNode));
    for(i=0;i<g->vertexNumber;i++) {
        g->vertex[i].firstEdge = NULL;
    }
    ListEdgeNode *listEdgeNode;
    for(k=0;k<g->edgeNumber;k++) {
        printf("请输入边(vi,vj)的下标,i和j,用空格隔开:");
        scanf("%d %d",&i,&j);
        listEdgeNode = (ListEdgeNode *)malloc(sizeof(ListEdgeNode));
        listEdgeNode->index = j;
        listEdgeNode->next = g->vertex[i].firstEdge;
        g->vertex[i].firstEdge = listEdgeNode;
        listEdgeNode = (ListEdgeNode*)malloc(sizeof(ListEdgeNode));
        listEdgeNode->index = i;
        listEdgeNode->next = g->vertex[j].firstEdge;
        g->vertex[j].firstEdge = listEdgeNode;
    }
    ListEdgeNode *len = NULL;
    for(i=0;i<g->vertexNumber;i++) {
        if(g->vertex[i].firstEdge!=NULL) {
            len = g->vertex[i].firstEdge;
        }
        while(len!=NULL) {
            printf("%d --- %d\t",i,len->index);
            len = len->next;
        }
        printf("\n");
    }
}

void main()
{
    GraphList *gl;
    gl = (GraphList*)malloc(sizeof(GraphList));
    GraphList_create(gl);
}

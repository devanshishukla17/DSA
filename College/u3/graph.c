/*
NON-LINEAR DATA STRUCTURE
TREE IS ALSO A GRAPH.
G=(V,E) V-set of vertices and E-set of edges
n is adjacent to m then n is successor and m is predecessor.
a graph which has atleast one cycle is cyclic graph.


*/

//ADJACENT MATRIX

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct graph
{
    int vertex; //nodes
    int adjmat[MAX][MAX]; //2d array
}GRAPH;

void create_matrix(GRAPH *g)
{
    int from,to;
    printf("Enter the number of vertices:\n");
    scanf("%d",&g->vertex);
    g->adjmat[0][0]=0;
    for(int i=1;i<=g->vertex;i++)
    {
        g->adjmat[0][i]=i; //columns as vertices
        g->adjmat[i][0]=i; //rows as vertices
        for(int j=1;j<g->vertex;j++)
        {
            g->adjmat[i][j]=0;
        }
    }
    while(1)
    {
        printf("\n Enter the from and to vertices: ");
        scanf("%d %d",&from,&to);
        if((from>0 && from<=g->vertex) && (to>0 && to<=g->vertex))
        {
            g->adjmat[from][to]=1; //directed graph
            //g->adjmat[to][from]=1; //undirected graph
        }
        else
        {
            break;
        }
    }
}

void display(GRAPH g)
{
    for(int i=0;i<=g.vertex;i++)
    {
        printf("\n");
        for(int j=0;j<=g.vertex;j++)
        {
            if(i==0 && j==0)
            {
                printf(" ");
            }               
            else
            {
                printf("%d ",g.adjmat[i][j]);
            } 
        }
    }
}

int main()
{
    GRAPH g;
    create_matrix(&g);
    display(g);
}

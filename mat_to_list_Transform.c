#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 50

//인접행렬
typedef struct Mat_GraphType
{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Mat_GraphType;

//인접 리스트
typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct List_GraphType
{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}List_GraphType;

void List_init(List_GraphType* g){
    int v;
    g->n =0;
    for ( v = 0; v < MAX_VERTICES; v++)
    {
        g->adj_list[v] = NULL;
    }
}

void Mat_init(Mat_GraphType* g){
    int r,c;
    g->n =0;
    for ( r = 0; r < MAX_VERTICES; r++)
    {
        for ( c = 0; c < MAX_VERTICES; c++)
        {
            g->adj_mat[r][c]=0;
        }
    }
}

void print_adj_list(List_GraphType* g){
    for (int i = 0; i < g->n; i++)
    {
        GraphNode* p = g->adj_list[i];
        
        printf("정점 %d의 인접 리스트", i);

        while (p!=NULL)
        {
            printf("-> %d ",p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void print_adj_mat(Mat_GraphType* g){
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++) 
        {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void mat_to_list_transform(Mat_GraphType* g1, List_GraphType* g2){
    g2->n = g1->n;
    for (int i = 0; i < g1->n; i++){
        GraphNode* p = g2->adj_list[i];
        //g2->adj_list[i] == NULL;
        while (p!=NULL)
        {
            g2->adj_list[i]==NULL;
            p = p->link;
        }
        
    }
    
    for (int i = 0; i < g1->n; i++){
        
        //g2->adj_list[i] == NULL;
        for (int j = 0; j < g1->n; j++){
            if(g1->adj_mat[i][j] == 1){//간선 존재여부 파악
                //새로운 노드 동적할당
                GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
                newNode->vertex = j;
                newNode->link = g2->adj_list[i];
                g2->adj_list[i] = newNode;
            }
        }        
    }
}
void list_to_mat_transform(List_GraphType* g1, Mat_GraphType* g2){
    g2->n = g1->n;
    //인접행렬 초기화
    for (int i = 0; i < g1->n; i++){
        for (int j = 0; j < g1->n; j++){
            g2->adj_mat[i][j]==0;
        }
    }

    for (int i = 0; i < g1->n; i++){
        GraphNode* p = g1->adj_list[i];
        while (p !=NULL){
            int j = p->vertex;
            g2->adj_mat[i][j] = 1;
            p = p->link;
        }
    }
}

int main(void){
    Mat_GraphType g1 = {4,{{0,1,1,1,},{1,0,1,0},{1,1,0,1},{1,0,1,0}}};
    List_GraphType g2;
    Mat_GraphType g3;

    mat_to_list_transform(&g1,&g2);
    print_adj_list(&g2);
    list_to_mat_transform(&g2,&g3);
    print_adj_mat(&g3);
    mat_to_list_transform(&g3,&g2);
    print_adj_list(&g2);
    return 0;
}
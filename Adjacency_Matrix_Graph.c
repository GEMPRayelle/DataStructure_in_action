#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphTree
{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphTree;

void init(GraphTree* g){
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

void insert_vertex(GraphTree* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
/*
void insert_vertex(GraphTree *g, int v) {
    if ((g->n + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
*/

void insert_edge(GraphTree* g, int start, int end){
    if(start>=g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

/*
void insert_edge(GraphTree *g, int start, int end) {
    if (start > g->n || end > g->n || start <= 0 || end <= 0) {
        fprintf(stderr, "그래프: 잘못된 정점 번호");
        return;
    }
    g->adj_mat[start - 1][end - 1] = 1;
    g->adj_mat[end - 1][start - 1] = 1;
}
*/

void print_adj_mat(GraphTree* g){
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//간선의 개수를 반환
int count_edges(GraphTree *g)
{
    int count = 0;
    for (int i = 0; i < g->n; i++)
    {
        for (int j = i + 1; j < g->n; j++)
        {
            if (g->adj_mat[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int find_degree(GraphTree *g, int n)
{
    int degree = 0;
    for (int i = 0; i < g->n; i++)
    {
        if (g->adj_mat[n-1][i] == 1)
        {
            degree++;
        }
    }
    return degree;
}

int edge_exist(GraphTree *g, int m, int n)
{
    return g->adj_mat[m][n] == 1;
}

/*
void list_conn_vertex(GraphTree *g, int n)
{
    printf("%d번 정점과 연결된 정점: ", n);
    for (int i = 0; i < g->n; i++)
    {
        if (g->adj_mat[n-1][i] == 1)
        {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}
*/

void list_conn_vertex(GraphTree *g, int n)
{
    printf("%d번 정점과 연결된 정점: ", n);
    for (int i = 0; i < g->n; i++)
    {
        if (g->adj_mat[n+1][i] == 1)
        {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

void main(){
    GraphTree *g;
    g = (GraphTree*)malloc(sizeof(GraphTree));
    init(g);
    for (int i = 0; i <= 4; i++){
        insert_vertex(g,i);
    }
    /*
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    */
    
    /*
    insert_edge(g,1,2);
    insert_edge(g,1,3);
    insert_edge(g,1,4);
    insert_edge(g,1,5);
    insert_edge(g,5,2);
    insert_edge(g,5,4);
    insert_edge(g,3,4);
    insert_edge(g,3,2);
    */
   
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,0,4);
    insert_edge(g,4,1);
    insert_edge(g,4,3);
    insert_edge(g,2,3);
    insert_edge(g,2,1);

    print_adj_mat(g);
    printf("간선의 개수: %d\n",count_edges(g));
    printf("1번 정점의 차수: %d\n", find_degree(g, 1));
    printf("간선 존재 여부 (2과 4 사이): %s\n", edge_exist(g, 2, 4) ? "참" : "거짓");
    list_conn_vertex(g, 2);

    free(g);
}
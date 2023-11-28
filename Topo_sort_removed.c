#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE -1
#define MAX_VERTICES 50
int removed[MAX_VERTICES];
int in_degree[MAX_VERTICES];//자기에게 들어오는 간선의 갯수

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g){
    int v;
    g->n =0;
    for ( v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        printf("그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v){
    GraphNode *node;
    if(u>=g->n || v >= g->n){
        printf("그래프: 정점번호 오류\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

int remove_zero_vertex(GraphType *g){
    for (int i = 0; i < g->n; i++){
        GraphNode *node = g->adj_list[i];
        if(removed[i] == 0 && in_degree[i] == 0){
            while (node != NULL){
                int u = node->vertex;
                in_degree[u]--;
                node = node->link;
            }
            removed[i] = TRUE;
            return i;
        }
    }
    return FALSE;
}

int topo_sort(GraphType *g){
    int i;
    GraphNode *node;

    for(i=0;i<g->n;i++){
        in_degree[i] = 0;
        removed[i] = 0;
    }
    for(i = 0; i < g->n; i++){
        GraphNode *node = g->adj_list[i];
        while(node != NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    int index;
    while ((index = remove_zero_vertex(g)) != -1){
        printf("정점 %d ->", index);
    }

    printf("\nindegree 배열: ");
    for (int i = 0; i < g->n; i++){
        printf("%d ", in_degree[i]);
    }

    printf("\nremoved 배열: ");
    for (int i = 0; i < g->n; i++){
        printf("%d ", removed[i]);
    }

    printf("\n");
    for ( i = 0; i < g->n; i++){
        if(removed[i] == 1) { return 1;}
        else{ return 0;}
    }
}

int main(void){
    GraphType g;

    graph_init(&g);
    insert_vertex(&g,0);
    insert_vertex(&g,1);
    insert_vertex(&g,2);
    insert_vertex(&g,3);
    insert_vertex(&g,4);
    insert_vertex(&g,5);

    insert_edge(&g,0,2);
    insert_edge(&g,0,3);

    
    insert_edge(&g,1,3);
    insert_edge(&g,1,4);

    insert_edge(&g,2,3);
    insert_edge(&g,2,5);
    
    insert_edge(&g,3,5);

    insert_edge(&g,4,5);

    if(topo_sort(&g))
        printf("위상순서가 있습니다.");
    else
        printf("위상순서가 없습니다.");

    return 0;
}
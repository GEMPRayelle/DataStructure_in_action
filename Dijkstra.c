#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VETICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VETICES][MAX_VETICES];
}GraphType;

int distance[MAX_VETICES];
int found[MAX_VETICES];
int prev_node[MAX_VETICES];//마지막 경유 노드

//찾지않은것중에 길이가 최소인것을찾는 함수
int choose(int distance[], int n,int found[]){
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for ( i = 0; i < n; i++){
        if(distance[i]<min&&!found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_status(GraphType* g){
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++)
    {
        if(distance[i]==INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for (int i = 0; i < g->n; i++)
        printf("%2d", found[i]);
    
    printf("\n");
    printf(" prev Node: ");
    for (int i = 0; i < g->n; i++){
       printf("%2d", prev_node[i]);
    }
    
    printf("\n\n");    
}

void shortest_path(GraphType* g, int start, int dest){
    int i,u,w;
    for ( i = 0; i < g->n; i++){
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
        prev_node[i] = start;//
    }
    found[start] = TRUE;
    distance[start] = 0;
    for ( i = 0; i < g->n-1; i++){
        print_status(g);
        u = choose(distance,g->n,found);
        found[u] = TRUE;
        if(dest == u) { break; }//도착점이 u와 같아지면 바로 종료
        for ( w = 0; w < g->n; w++){
            if(!found[w])
                if(distance[u] + g->weight[u][w]<distance[w]){
                    distance[w] = distance[u] + g->weight[u][w];
                    prev_node[w] = u; //직전 경유 노드 저장
                }
        }
    }
    print_status(g);
}

void print_shortest_path(int start, int dest){
    printf("%d 부터 %d까지의 최단경로: %d", start, dest, dest);
    int temp = dest;
    while (temp != start) {
        printf(" <- %d", prev_node[temp]);
        temp = prev_node[temp];
    }
    printf("\n");
}

int main(void){
    
    GraphType g = {7,
    {{0,7,INF,INF,3,10,INF},
    {7,0,4,10,2,6,INF},
    {INF,4,0,2,INF,INF,INF},
    {INF,10,2,0,11,9,4},
    {3,2,INF,11,0,INF,5},
    {10,6,INF,9,INF,0,INF},
    {INF,INF,INF,4,5,INF,0}}
    };
    int start = 1;
    int dest = 3;
    shortest_path(&g, start, dest);
    print_shortest_path(start, dest);
    /*
    GraphType g = {8,
    {{0,7,INF,5,INF,2,INF,INF},
    {7,0,6,INF,2,INF,INF,1},
    {INF,6,0,2,INF,INF,2,8},
    {5,INF,2,0,INF,5,INF,INF},
    {INF,2,INF,INF,0,2,INF,4},
    {2,INF,INF,5,2,0,4,INF},
    {INF,INF,2,INF,INF,4,0,4},
    {INF,1,8,INF,4,INF,4,0}}
    };*/
    //shortest_path(&g, 0, 6);
    
    return 0;
}
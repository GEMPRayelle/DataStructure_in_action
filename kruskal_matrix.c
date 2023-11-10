#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
#define INF 1000L

int parent[MAX_VERTICES];

typedef struct Mat_GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} Mat_GraphType;

struct Edge {
    int start, end, weight;
};

void set_init(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int crr) {
    if (parent[crr] == -1)
        return crr;
    while (parent[crr] != -1)
        crr = parent[crr];
    return crr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2) {
        parent[root1] = root2;
        printf("Union: %d -> %d\n", root1, root2);
    }
}

int compare(const void *a, const void *b) {
    struct Edge *x = (struct Edge *)a;
    struct Edge *y = (struct Edge *)b;
    return (x->weight - y->weight);
}

// Kruskal 알고리즘 구현
void Kruskal(Mat_GraphType* g) {
    // 모든 간선을 추출하여 가중치에 따라 정렬
    int edge_accepted = 0;
    int uset, vset;
    struct Edge edges[MAX_VERTICES * MAX_VERTICES];
    
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adj_mat[i][j] != INF) {
                edges[edge_accepted].start = i;
                edges[edge_accepted].end = j;
                edges[edge_accepted].weight = g->adj_mat[i][j];
                edge_accepted++;
            }
        }
    }
    //집합 초기화
    set_init(g->n);
    qsort(edges, edge_accepted, sizeof(struct Edge), compare);
    

    // Kruskal 알고리즘 수행
    printf("크루스칼 최소 신장 트리 알고리즘:\n");
    for (int i = 0; i < edge_accepted; i++) {
        uset = set_find(edges[i].start);
        vset = set_find(edges[i].end);
        if (uset != vset) {
            printf("간선 (%d, %d) %d 선택\n", edges[i].start, edges[i].end, edges[i].weight);
            set_union(uset, vset);
        }
    }
}

int main(void) {
    Mat_GraphType g = {
        7,
        {{0, 29, INF, INF, INF, 10, INF},
         {29, 0, 16, INF, INF, INF, 15},
         {INF, 16, 0, 12, INF, INF, INF},
         {INF, INF, 12, 0, 22, INF, 18},
         {INF, INF, INF, 22, 0, 27, 25},
         {10, INF, INF, INF, 27, 0, INF},
         {INF, 15, INF, 18, 25, INF, 0}
        }
    };

    Kruskal(&g);

    return 0;
}
#include <stdio.h>
#include <math.h>

#define SIZE 64

typedef struct {
   int heap[SIZE];
   int heap_size;
} HeapType;

void print_heap_tree(HeapType *h) 
{
    int i = 1;
    int k = 1;
    printf("\n히프트리\n");
    while (i <= h->heap_size){
        for(int j = 1; j <= pow(2, k-1); j++){
            if(i > h->heap_size){ break; }
            printf("%d,", h->heap[i]);
            i++;
        }
        printf("\n");
        k++;
    }
}

int main(void)
{
    int i;
    HeapType heap;
    
    // make sample heap tree with SIZE -1
    for (i = 1; i <= SIZE - 1; i++)
        heap.heap[i] = SIZE - i;

    heap.heap_size = SIZE - 1;
    print_heap_tree(&heap); 
    return 0;
}

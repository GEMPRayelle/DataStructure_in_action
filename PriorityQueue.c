#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
//삭제연산에서는 루트만 삭제가능(우선순위가 가장높기때문에)
//히프는 완전이진트리, n개의 노드를 가지고있는 히프의 높이는 O(logn)

typedef struct 
{
    int key;
} element;
typedef struct 
{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size = 0;
}   

void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key >h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
    
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        if((child<h->heap_size)&&(h->heap[child].key) < h->heap[child+1].key)
            child++;
        if(temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
void printHeap(HeapType* h){
    int i;
    printf("히프트리가 저장된 배열 : ");
    for (i = 1; i <= h->heap_size; i++)
    {
        printf("[%d] ", h->heap[i]);
    }    
}

int main(void){
    element e1 = {10}, e2={40},e3={30},e4={5},e5={12},e6={6},e7={15},e8={9},e9={60};
    element e10,e11,e12,e13,e14,e15,e16,e17,e18;
    HeapType* heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1); insert_max_heap(heap, e2);
    insert_max_heap(heap, e3); insert_max_heap(heap, e4);
    insert_max_heap(heap, e5);
    insert_max_heap(heap, e6);
    insert_max_heap(heap, e7);
    insert_max_heap(heap, e8);
    insert_max_heap(heap, e9);
    printHeap(heap);
    printf("\n");

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);
    e11 = delete_max_heap(heap);
    printf("< %d > ", e11.key);
    e12 = delete_max_heap(heap);
    printf("< %d > ", e12.key);
    e13 = delete_max_heap(heap);
    printf("< %d > ", e13.key);
    e14 = delete_max_heap(heap);
    printf("< %d > ", e14.key);
    e15 = delete_max_heap(heap);
    printf("< %d > ", e15.key);
    e16 = delete_max_heap(heap);
    printf("< %d > ", e16.key);
    e17 = delete_max_heap(heap);
    printf("< %d > ", e17.key);
    e18 = delete_max_heap(heap);
    printf("< %d > ", e18.key);

    free(heap);
    return 0;
}
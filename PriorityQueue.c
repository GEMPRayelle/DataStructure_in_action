//이진트리를 동적메모리로서 트리모양으로 표현하고, 히프트리는 배열로서 표현하기에
//완전이진트리로서 빈칸이없이 배열을 채울수있음, 중위순회나 이진탐색트리는 자기 부모를 찾는 연산이없음
//히프트리는 완전이진트리이기도하고 히프트리의연산들은 자기의 부모를찾는 연산이 많아 배열로서 표현할수있는
//히프트리가 더 장점이 많다

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    //HeapType*주소값을 돌려줌,HeapType만큼 메모리를 받아서
}

void init(HeapType* h){
    h->heap_size = 0;//초기화
    //h가 가리키는 구조체의 힙사이즈 필드를 0으로 만들어라
}   

void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);//힙사이즈 1개 증가

    while ((i != 1) && (item.key >h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;//새로운노드를삽입
    
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];//가장큰값
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

void print_heap_tree(HeapType* h){
    int i = 1;
    int k = 1;
    printf("\n히프트리\n");
    while (i <= h->heap_size){
        for(int j = 1; j <= pow(2, k-1); j++){
            if(i > h->heap_size){
                break;
            }
            printf("%2d  ", h->heap[i].key);
            i++;
        }
        printf("\n");
        k++;
    }
}
/*
void print_heap_tree_recursive(HeapType* h, int index, int level) {
    if (index <= h->heap_size) {
        print_heap_tree_recursive(h, 2 * index + 1, level + 1);

        for (int i = 0; i < level; i++) {
            printf("   "); // Adjust the number of spaces for indentation
        }

        printf("%d\n", h->heap[index].key);

        print_heap_tree_recursive(h, 2 * index, level + 1);
    }
}

void print_heap_tree(HeapType* h) {
    if (h->heap_size == 0) {
        printf("Heap is empty.\n");
    } else {
        print_heap_tree_recursive(h, 1, 0);
    }
} */

int main(void){
    //구조체 타입이라 {}를 사용해 값을 넣어줌
    element e1 = {10}, e2={40},e3={30},e4={5},e5={12},e6={6},e7={15};
    element e8,e9,e10,e11,e12,e13,e14;
    HeapType* heap;//heap포인터변수를 생성(주소가 들어감),나중에 HeapType모양의 주소를 가질수있음
    //지금 이상태에서는 쓰레기상태 아무런 값도 못받음

    heap = create();//주소를 heap에 넣어줌
    init(heap);

    insert_max_heap(heap, e1); 
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    insert_max_heap(heap, e4);
    insert_max_heap(heap, e5);
    insert_max_heap(heap, e6);
    insert_max_heap(heap, e7);
    //printHeap(heap);
    print_heap_tree(heap);
    printf("\n");

    e8= delete_max_heap(heap);
    printf("< %d > ", e8.key);
    e9 = delete_max_heap(heap);
    printf("< %d > ", e9.key);
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
    free(heap);
    return 0;
}
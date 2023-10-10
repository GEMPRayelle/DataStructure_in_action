//히프복잡도
//삽입 연산에서 최악의 경우 O(logn)=루트 노드까지 올라가야 하므로 트리의 높이에
//해당하는 비교 연산 및 이동 연산이 필요하다
//삭제도 최악의 경우 가장 아래 레벨까지 내려가야 하므로 역시 트리의 높이만큼
//시간이 걸린다 O(logn) n=노드의 갯수

//트리비교성능차이=
/*완전이진트리 는 항상 노드의 갯수에 비해서 logn만큼 높이가 만들어짐
이진탐색트리는 데이터가 오는 순서에 따라 만들어지는 모양이 다름
확률에 따라 좋지않은 모양이 나올 가능성이 있음
*/

//히프정렬(별로 좋진않음) > 퀵정렬,합병정렬이 더 좋음, 
//*히프를 이렇게 정렬할수가있다 정도만 알기
//먼저 정렬해야할 n개의 요소를 최대히프에 삽입
//한번에 하나씩 요소를 히프에서 삭제하여 저장하면됨
//하나의 요소를 히프에 삽입하거나 삭제할떄 시간이 O(logn)만큼 소요되고 
//요소의개수가n개이므로 O(nlogn)만큼 걸린다
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

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

void  heap_sort(element a[], int n){
    int i;
    HeapType* h;

    h=create();
    init(h);
    for (i = 0; i < n; i++)
    {
        insert_max_heap(h,a[i]);
    }
    for ( i = (n-1); i >= 0; i--)
    {
        a[i] = delete_max_heap(h);
    }
    free(h);   
}
#define SIZE 8
int main(void){
    element list[SIZE] = {23,56,11,9,56,99,27,34};
    heap_sort(list,SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i].key);
    }
    printf("\n");
    return 0;
    
}
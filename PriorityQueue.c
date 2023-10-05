//����Ʈ���� �����޸𸮷μ� Ʈ��������� ǥ���ϰ�, ����Ʈ���� �迭�μ� ǥ���ϱ⿡
//��������Ʈ���μ� ��ĭ�̾��� �迭�� ä�������, ������ȸ�� ����Ž��Ʈ���� �ڱ� �θ� ã�� �����̾���
//����Ʈ���� ��������Ʈ���̱⵵�ϰ� ����Ʈ���ǿ������ �ڱ��� �θ�ã�� ������ ���� �迭�μ� ǥ���Ҽ��ִ�
//����Ʈ���� �� ������ ����

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ELEMENT 200
//�������꿡���� ��Ʈ�� ��������(�켱������ ������⶧����)
//������ ��������Ʈ��, n���� ��带 �������ִ� ������ ���̴� O(logn)

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
    //HeapType*�ּҰ��� ������,HeapType��ŭ �޸𸮸� �޾Ƽ�
}

void init(HeapType* h){
    h->heap_size = 0;//�ʱ�ȭ
    //h�� ����Ű�� ����ü�� �������� �ʵ带 0���� ������
}   

void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);//�������� 1�� ����

    while ((i != 1) && (item.key >h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;//���ο��带����
    
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];//����ū��
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
    printf("����Ʈ���� ����� �迭 : ");
    for (i = 1; i <= h->heap_size; i++)
    {
        printf("[%d] ", h->heap[i]);
    }    
}

void print_heap_tree(HeapType* h){
    int i = 1;
    int k = 1;
    printf("\n����Ʈ��\n");
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
    //����ü Ÿ���̶� {}�� ����� ���� �־���
    element e1 = {10}, e2={40},e3={30},e4={5},e5={12},e6={6},e7={15};
    element e8,e9,e10,e11,e12,e13,e14;
    HeapType* heap;//heap�����ͺ����� ����(�ּҰ� ��),���߿� HeapType����� �ּҸ� ����������
    //���� �̻��¿����� ��������� �ƹ��� ���� ������

    heap = create();//�ּҸ� heap�� �־���
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
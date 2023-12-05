#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct Person{
    int weight;
    int key;
}Person;

int list[MAX_SIZE];
int n;


void insert_sort_Person_weight(Person person[], int n){
    int i,j;
    Person key;
    for ( i = 0; i < n; i++){
        key = person[i];
        for ( j = i-1; j >= 0 && person[j].weight>key.weight; j--)
            person[j+1] = person[j];
        person[j+1] = key;
    }
}

//�������� ���� ���ĵǾ��ִ��͵��� �ڸ��� �ٲ��� �ʱ� ������ �������� �ִٰ� ����
void insert_sort_Person_key(Person person[], int n){
    int i,j;
    Person key;
    for ( i = 0; i < n; i++){
        key = person[i];
        for ( j = i-1; j >= 0 && person[j].key>key.key; j--)
            person[j+1] = person[j];
        person[j + 1] = key;
    }   
}

int main(void){
    Person person[MAX_SIZE] = {{3,120},{5,130},{19,150},{4,120},{20,180},{11,120},
    {7,120},{35,300},{1,111},{6,165}};
    Person person2[MAX_SIZE] = {{3,120},{5,130},{19,150},{4,120},{20,180},{11,120},
    {7,120},{35,300},{1,111},{6,165}};

    int i;
    n = MAX_SIZE;
    
    insert_sort_Person_weight(person, n);
    printf("�����Է� �����ҽ�\n");
    printf("weight:");
    for ( i = 0; i < n; i++)
        printf("%d ", person[i].weight);
    printf("\n");
    printf("key:");
    for ( i = 0; i < n; i++)
        printf("%d ", person[i].key);
    printf("\n\n");

    insert_sort_Person_key(person2, n);
    printf("Ű�� �����ҽ�\n");
    printf("weight:");
    for ( i = 0; i < n; i++)
        printf("%d ", person2[i].weight);
    printf("\n");
    printf("key:");
    for ( i = 0; i < n; i++)
        printf("%d ", person2[i].key);
    return 0;
}
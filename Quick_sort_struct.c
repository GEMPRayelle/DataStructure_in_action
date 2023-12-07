#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t));

typedef struct stdtype{
    int stid;
    char stname[20];
}stdtype;

int list[MAX_SIZE];
int n;
int partition(int list[], int left, int right){
    int pivot, temp;
    int low,high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do
            low++;
        while(list[low]<pivot);
        do
            high--;
        while(list[high>pivot]);
        if(low<high) SWAP(list[low],list[high],temp);
    }while(low<high);

    SWAP(list[left],list[high],temp);
    return high;
}

void quick_sort(int list[], int left, int right){
    if(left<right){
        int q= partition(list, left, right);
        quick_sort(list,left,q-1);
        quick_sort(list,q+1,right);
    }
}

int compare_name(const void *arg1, const void *arg2){
    return (strncmp(((stdtype*)arg1)->stname,
    ((stdtype*)arg2)->stname,20));
}
int compare_id(const void *arg1, const void *arg2){
    if(((stdtype*)arg1)->stid > ((stdtype*)arg2)->stid) return 1;
    else if(((stdtype*)arg1)->stid == ((stdtype*)arg2)->stid) return 0;
    else return -1;
}

//void *base:일반 포인터(모든것의 포인터, int든 문자열이든 **든 될수있음)
//함수포인터:int를 반환하는 함수의 포인터 int(*compare)
//int a[10] = &a[0]
int main(void){
    stdtype std[10] = {{3,"Hong"},{3,"John"},{2,"Kim"},{2,"Park"},{1,"Doug"},{4,"Lee"},{3,"Lee"},{1,"Son"},
    {4,"Do"},{1,"Joo"}};
    stdtype std2[10] = {{3,"Hong"},{3,"John"},{2,"Kim"},{2,"Park"},{1,"Doug"},{4,"Lee"},{3,"Lee"},{1,"Son"},
    {4,"Do"},{1,"Joo"}};
    
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for ( i = 0; i < n; i++)
        list[i]=rand()%100;

    qsort((void*)std,10,sizeof(stdtype),compare_id);

    printf("학년으로 정렬\n");
    for ( i = 0; i < n; i++)
        printf("%d ", std[i].stid);
    printf("\n");
    for ( i = 0; i < n; i++)
        printf("%s ", std[i].stname);
    printf("\n");


    qsort((void*)std2,10,sizeof(stdtype),compare_name);
    printf("이름으로 정렬\n");
    for ( i = 0; i < n; i++)
        printf("%d ", std2[i].stid);
    printf("\n");
    for ( i = 0; i < n; i++)
        printf("%s ", std2[i].stname);
    printf("\n");
    return 0;

    
}
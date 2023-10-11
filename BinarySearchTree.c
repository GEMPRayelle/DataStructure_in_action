//탐색작업을 효율적으로 하기 위한 자료구조
//key(왼쪽서브트리)<=key(루트노드)<=key(오른쪽서브트리)
//이진탐색 트리를 중위순회하면 오름차순으로 정렬된 값을 얻을 수 있다.
//순차탐색 시간복잡도 O(n), 이진탐색 시간복잡도 O(logn) 이게 더 빠름 but 크기 순으로 정렬이 되 있어야만 이진탐색가능
//가장 중간부터 보고 88보다 더 작으면 오른쪽 중간 검색후 다시 왼쪽 오른쪽 결정
//정렬이 되어있으면 이진탐색 아닐시 그냥 순차탐색
//O(nlogn)

//탐색 구현 방법중 반복적과 순환적중 순환적방법이 더 편함(이것만 집중적으로 하기)
//데이터 순서에따라 트리가 균형일수있고 경사이진트리가 될 수 있음
//이진탐색트리의 중요도(중), 쓰레드 이진트리는 중요도(하), 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))

typedef int element;
typedef struct TreeNode
{
    element key;
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int get_node_count(TreeNode *root){
    int count = 0;
    if(root != NULL)
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    return count;
}

int get_leaf_count(TreeNode *root){
    int count = 0;

    if(root != NULL){
        if(root->left == NULL && root->right == NULL)
            return 1;
        else
            count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int get_height(TreeNode *root){
    int height = 0;
    if(root != NULL)
        height = 1 + max(get_height(root->left), get_height(root->right));
        
        
    return height;
}

TreeNode *search(TreeNode *node, int key){
    if(node =NULL) return NULL;
    if(key == node->key) return node;
    else if(key<node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

int main(void){
    TreeNode *n1, *n2, *n3 ,*n4 ,*n5 ,*n6, *n7;
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    n4 = (TreeNode*)malloc(sizeof(TreeNode));
    n5 = (TreeNode*)malloc(sizeof(TreeNode));
    n6 = (TreeNode*)malloc(sizeof(TreeNode));
    n7 = (TreeNode*)malloc(sizeof(TreeNode));
    n1->data=15;
    n1->left=n2;
    n1->right=n3;
    n2->data=4;
    n2->left=n4;
    n2->right=NULL;
    n4->data=1;
    n4->left=NULL;
    n4->right=NULL;
    n3->data=20;
    n3->left=n5;
    n3->right=n6;
    n5->data=18;
    n5->left=n7;
    n5->right=NULL;
    n6->data=25;
    n6->left=NULL;
    n6->right=NULL;
    n7->data=16;
    n7->left=NULL;
    n7->right=NULL;
    TreeNode *root = n1;

    printf("트리의 전체노드 갯수는 %d개입니다.\n",get_node_count(root));
    printf("트리의 단말노드 갯수는 %d개입니다.\n",get_leaf_count(root));
    printf("트리의 높이는 %d입니다.\n", get_height(root));
    printf("\n");

    return 0;
}
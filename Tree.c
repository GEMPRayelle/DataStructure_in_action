//트리에서 사이클은 (3개의 노드가 다 연결)존재하지않음 > 사이클이 있을시 트리x 그래프o
//트리의 구성요소 - 노드, 부모가 없는 노드-root, 
//하나의 노드와 그 노드들의 자손들로 이루어진 트리 - 서브트리
//자식이없는노드 - 단말노드, 적어도 하나의 자식을 가지는 노드 - 비단말노드
//레벨 - 트리의 각층의 번호, 높이 -트리의 최대 레벨, 차수(degree) - 노드가 가지고 있는 자식 노드의 개수
//트리의 종류중 일반 트리는 잘 쓰지않음, 이진 트리 사용

//이진트리:모든노드가 2개의 서브트리를 가짐(서브트리는 공집합일 수 있다 ex O(root)-O, O-O(root))
//->최대 2개까지의 자식 노드가 존재, 모든 노드의 차수가 2 이하가 됨->구현하기편리
//이진트리에는 서브트리간의 순서가 존재
//8.1정의를 만족해야함
//노드의 개수가 n개일시 간선의 개수는 n-1개
//높이가 h인 이진트리는 최소 h개의 노드를 가지며 최대 2^h-1개의 노드를 가진다
//n개의 노드를 가지는 이진트리 높이 = 최대n ,쵯 log2(n+1) 
//포화이진트리:트리의 각 레벨의 노드가 꽉 차있는 이진트리 
/*완전이진트리:레벨1부터 k-1까지는 노드가 모두 채워져있고 
마지막 레벨k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져있는 이진트리*/
//기타이전트리

//이진트리 표현 - 배열이용, 포인터 이용(주로 사용)
//배열표현법-이진트리를 포화이진트리라 가정하고 사용 (인덱스0번 사용안함)
//링크표현법-포인터를 사용하여 표현 

//전위순회, *중위순회, 후위순회
//
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

void main(){
    TreeNode *n1, *n2, *n3;
    n1=(TreeNode*)malloc(sizeof(TreeNode));//힙에서 만들어져 지역변수n1이 가리킴
    n2=(TreeNode*)malloc(sizeof(TreeNode));//지역변수는 사라질 수 있지만, malloc으로 만든 공간은프로그램이 끝날때까지 안없어짐
    n3=(TreeNode*)malloc(sizeof(TreeNode));
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;
    n2->data = 20;
    n2->left = NULL;
    n2->right = NULL;
    n3->data = 30;
    n3->left = NULL;
    n3->right = NULL;
    free(n1); free(n2); free(n3);
    return 0;
}
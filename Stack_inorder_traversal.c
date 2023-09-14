#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];//*는 stack배열에[0~99] TreeNode의 포인터(주소)가 들어간다는 뜻

void push(TreeNode *p){
    if(top < SIZE-1)
        stack[++top] = p;
}

TreeNode *pop(){
    TreeNode *p = NULL;
    if(top>=0)
        p = stack[top--];
    return p;
}

//순환-편리 속도낮음, 반복-속도높음
void inorder_iter(TreeNode *root){
    while (1)
    {
        for ( ; root ; root = root->left)//루트 부터 시작해서 
        {
            push(root);
        }
        root = pop();
        if(!root) break;//루트가 NULL이면
        printf("[%d] ", root->data);
        root = root->right;
    }   
}

TreeNode n1 = {1,NULL,NULL};
TreeNode n2 = {4,&n1,NULL};
TreeNode n3 = {16,NULL,NULL};
TreeNode n4 = {25,NULL,NULL};
TreeNode n5 = {20,&n3,&n4};
TreeNode n6 = {15,&n2,&n5};
TreeNode *root = &n6;

int main(void){
    printf("중위순회: ");
    inorder_iter(root);
    printf("\n");
    return 0;
}

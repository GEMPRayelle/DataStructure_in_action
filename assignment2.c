#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;



//전위 순회
void preorder(TreeNode *root){
    if(root != NULL){
        printf("[%d] ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void){
    TreeNode *n1, *n2, *n3 ,*n4 ,*n5 ,*n6;
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    n4 = (TreeNode*)malloc(sizeof(TreeNode));
    n5 = (TreeNode*)malloc(sizeof(TreeNode));
    n6 = (TreeNode*)malloc(sizeof(TreeNode));
    n1->data=15;
    n1->left=n2;
    n1->right=n3;
    n2->data=4;
    n2->left=n4;
    n2->right=n5;
    n4->data=1;
    n4->left=NULL;
    n4->right=NULL;
    n5->data=8;
    n5->left=NULL;
    n5->right=NULL;
    n3->data=20;
    n3->left=NULL;
    n3->right=n6;
    n6->data=25;
    n6->left=NULL;
    n6->right=NULL;
    TreeNode *root = n1;

    printf("전위 순회=");
    preorder(root);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct TreeNode
{
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
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <stdbool.h>
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int get_height(TreeNode *root){
    int height = 0;
    if(root != NULL)
        height = 1 + max(get_height(root->left), get_height(root->right));
           
    return height;
}

//���� Ʈ���� ���� Ʈ������ �˻��ϴ� �Լ�
bool isBalanced(TreeNode *root){
    if(root==NULL)
        return false;
    int leftHeight = get_height(root->left);
    int rightHeight = get_height(root->right);
    if((leftHeight - rightHeight) > 1 || (leftHeight - rightHeight) < -1){
        return false;
    }
    else{
        return true;
    }
    
}

//��尡 ������ �ִ� ���� ���� ����ϴ� �Լ�
int get_SumOfNode(TreeNode *root){
    if(root == NULL){
            return 0; // ��尡 ������ ���� 0
    }
    else{
        // ���� ����� ���� ���� ����Ʈ���� ������ ����Ʈ���� ���� ���Ͽ� ��ȯ        
        int sum = root->data + get_SumOfNode(root->left) + get_SumOfNode(root->right);
        return sum;
    }
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
    n1->data=15;n1->left=n2;n1->right=n3;
    n2->data=4;n2->left=n4;n2->right=NULL;
    n4->data=1;n4->left=NULL;n4->right=NULL;
    n3->data=20;n3->left=n5;n3->right=n6;
    n5->data=18;n5->left=n7;n5->right=NULL;
    n6->data=25;n6->left=NULL;n6->right=NULL;
    n7->data=16;n7->left=NULL;n7->right=NULL;
    TreeNode *root = n1;

    TreeNode *r1, *r2, *r3 ,*r4 ,*r5 ,*r6;
    r1 = (TreeNode*)malloc(sizeof(TreeNode));
    r2 = (TreeNode*)malloc(sizeof(TreeNode));
    r3 = (TreeNode*)malloc(sizeof(TreeNode));
    r4 = (TreeNode*)malloc(sizeof(TreeNode));
    r5 = (TreeNode*)malloc(sizeof(TreeNode));
    r6 = (TreeNode*)malloc(sizeof(TreeNode));
    r1->data=15;r1->left=r2;r1->right=r3;
    r2->data=4;r2->left=NULL;r2->right=NULL;
    r3->data=20;r3->left=r4;r3->right=r5;
    r4->data=18;r4->left=r6;r4->right=NULL;
    r5->data=25;r5->left=NULL;r5->right=NULL;
    r6->data=16;r6->left=NULL;r6->right=NULL;
    TreeNode *root1 = r1;

    printf("���� Ʈ�� �˻��� %d\n", isBalanced(root));
    printf("����� ���� %d�Դϴ�.", get_SumOfNode(root));
    printf("\n\n");
    printf("���� Ʈ�� �˻��� %d\n", isBalanced(root1));
    printf("����� ���� %d�Դϴ�.", get_SumOfNode(root1));
    printf("\n");

    return 0;
}
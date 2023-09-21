//Ž���۾��� ȿ�������� �ϱ� ���� �ڷᱸ��
//key(���ʼ���Ʈ��)<=key(��Ʈ���)<=key(�����ʼ���Ʈ��)
//����Ž�� Ʈ���� ������ȸ�ϸ� ������������ ���ĵ� ���� ���� �� �ִ�.
//����Ž�� �ð����⵵ O(n), ����Ž�� �ð����⵵ O(logn) �̰� �� ���� but ũ�� ������ ������ �� �־�߸� ����Ž������
//���� �߰����� ���� 88���� �� ������ ������ �߰� �˻��� �ٽ� ���� ������ ����
//������ �Ǿ������� ����Ž�� �ƴҽ� �׳� ����Ž��
//O(nlogn)

//Ž�� ���� ����� �ݺ����� ��ȯ���� ��ȯ������� �� ����(�̰͸� ���������� �ϱ�)
//������ ���������� Ʈ���� �����ϼ��ְ� �������Ʈ���� �� �� ����
//����Ž��Ʈ���� �߿䵵(��), ������ ����Ʈ���� �߿䵵(��), 
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

    printf("Ʈ���� ��ü��� ������ %d���Դϴ�.\n",get_node_count(root));
    printf("Ʈ���� �ܸ���� ������ %d���Դϴ�.\n",get_leaf_count(root));
    printf("Ʈ���� ���̴� %d�Դϴ�.\n", get_height(root));
    printf("\n");

    return 0;
}
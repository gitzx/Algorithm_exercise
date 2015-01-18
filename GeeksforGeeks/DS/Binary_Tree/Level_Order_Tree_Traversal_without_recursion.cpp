#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 500
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode **createQueue(int *front, int *rear){
    TreeNode **queue=(TreeNode **)malloc(sizeof(TreeNode*)*MAX_SIZE);
    *front=*rear=0;
    return queue;
}

void enQueue(TreeNode **queue,int *rear,TreeNode *new_node){
    queue[*rear]=new_node;
    (*rear)++;
}

TreeNode *deQueue(TreeNode **queue, int *front){
    (*front)++;
    return queue[*front-1];
}

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void printLevelOrder(TreeNode *root){
    int rear, front;
    TreeNode **queue=createQueue(&front,&rear);
    TreeNode *temp_node=root;
    while(temp_node){
        cout<<temp_node->data<<" ";
        if(temp_node->left){
            enQueue(queue,&rear,temp_node->left);
        }
        if(temp_node->right){
            enQueue(queue,&rear,temp_node->right);
        }
        temp_node=deQueue(queue,&front);
    }
    cout<<endl;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    printLevelOrder(root); //1 2 3 4 5
    return 0;
}



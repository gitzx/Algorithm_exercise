#include <iostream>
#include <stdlib.h>
#define MAX_Q_SIZE 500
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode **createQueue(int *front,int *rear){
    TreeNode **queue=(TreeNode**)malloc(sizeof(TreeNode*)*MAX_Q_SIZE);
    *front=*rear=0;
    return queue;
}

void enQueue(TreeNode **queue,int *rear,TreeNode *new_node){
    queue[*rear]=new_node;
    (*rear)++;
}

TreeNode *deQueue(TreeNode **queue,int *front){
    (*front)++;
    return queue[*front-1];
}

bool isQueueEmpty(int *front,int *rear){
    return (*rear==*front);
}

TreeNode *newNode(int data){
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

bool isCompleteBT(TreeNode *root){
    if(root==NULL){
        return true;
    }
    int rear,front;
    TreeNode **queue=createQueue(&front,&rear);
    bool flag=false;
    enQueue(queue,&rear,root);
    while(!isQueueEmpty(&front,&rear)){
        TreeNode *temp_node=deQueue(queue,&front);
        if(temp_node->left){
            if(flag==true){
                return false;
            }
            enQueue(queue,&rear,temp_node->left);
        }else{
            flag=true;
        }
        if(temp_node->right){
            if(flag==true){
                return false;
            }
            enQueue(queue,&rear,temp_node->right);
        }else{
            flag=true;
        }
    }
    return true;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    int isComplete=isCompleteBT(root);
    cout<<isComplete<<endl; //0
    return 0;
}

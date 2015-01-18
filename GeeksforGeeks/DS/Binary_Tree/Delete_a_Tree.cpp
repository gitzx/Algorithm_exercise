#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void deleteT(TreeNode *node){
    if(node==NULL){
        return;
    }
    deleteT(node->left);
    deleteT(node->right);
    cout<<"Deleting:"<<node->data<<endl;
    free(node);
}

void deleteTree(TreeNode **node_ref){
    deleteT(*node_ref);
    *node_ref=NULL;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    deleteTree(&root);
    return 0;
}

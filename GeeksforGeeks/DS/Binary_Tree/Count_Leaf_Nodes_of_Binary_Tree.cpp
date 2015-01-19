#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

int getLeafCount(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    if(node->left==NULL&&node->right==NULL){
        return 1;
    }else{
        return getLeafCount(node->left)+getLeafCount(node->right);
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<getLeafCount(root)<<endl; //3
    return 0;
}

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

int max(int a,int b){
    return a>b?1:0;
}

int height(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    return 1+max(height(node->left),height(node->right));
}

int isBalanced(TreeNode *node){
    if(node==NULL){
        return 1;
    }
    int lheight=isBalanced(node->left);
    int rheight=isBalanced(node->right);
    if(abs(lheight-rheight)<=1&&
            isBalanced(node->left)&&isBalanced(node->right)){
        return 1;
    }
    return 0;
}

int main(){
    TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
    root->left=newNode(1);
    root->right=newNode(2);
    root->left->left=newNode(3);
    cout<<isBalanced(root)<<endl; //1
    return 0;
}

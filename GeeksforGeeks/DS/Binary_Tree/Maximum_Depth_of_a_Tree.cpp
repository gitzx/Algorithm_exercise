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

int maxDepth(TreeNode *node){
    if(node==NULL){
        return 0;
    }else{
        int lDepth=maxDepth(node->left);
        int rDepth=maxDepth(node->right);
        if(lDepth>rDepth){
            return lDepth+1;
        }else{
            return rDepth+1;
        }
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<maxDepth(root)<<endl; //3
    return 0;
}

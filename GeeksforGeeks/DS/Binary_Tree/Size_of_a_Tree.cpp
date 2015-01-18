//Size of a tree is the number of elements present in the tree

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

int size(TreeNode *node){
    if(node==NULL){
        return 0;
    }else{
        return (size(node->left)+1+size(node->right));
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<size(root)<<endl; //5
    return 0;
} 

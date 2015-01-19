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

void mirror(TreeNode *node){
    if(node==NULL){
        return;
    }else{
        mirror(node->left);
        mirror(node->right);
        TreeNode *temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}

void inorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
   TreeNode *root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   inorder(root);
   cout<<endl; //2 1 3
   mirror(root);
   inorder(root); //3 1 2
   cout<<endl;
   return 0;
}

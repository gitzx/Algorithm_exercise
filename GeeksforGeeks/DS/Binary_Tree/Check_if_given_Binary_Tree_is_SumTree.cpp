#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=new TreeNode;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

int sum(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+root->data+sum(root->right);
}

int isSumTree(TreeNode *node){
    if(node==NULL||node->left==NULL&&node->right==NULL){
        return 1;
    }
    int ls=sum(node->left);
    int rs=sum(node->right);
    if(node->data==ls+rs&&isSumTree(node->left)&&isSumTree(node->right)){
        return 1;
    }
    return 0;
}

int main(){
    TreeNode *root=newNode(8);
    root->left=newNode(3);
    root->right=newNode(2);
    root->left->left=newNode(2);
    root->left->right=newNode(1);
    cout<<isSumTree(root)<<endl; //1
    return 0;
}

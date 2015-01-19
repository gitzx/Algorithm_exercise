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

int isSumProperty(TreeNode *node){
    int left_data=0;
    int right_data=0;
    if(node==NULL||node->left==NULL&&node->right==NULL){
        return 1;
    }else{
        if(node->left!=NULL){
            left_data=node->left->data;
        }
        if(node->right!=NULL){
            right_data=node->right->data;
        }
        if((node->data==left_data+right_data)&&
                isSumProperty(node->left)&&
                isSumProperty(node->right)){
            return 1;
        }else{
            return 0;
        }
    }
}

int main(){
    TreeNode *root=newNode(5);
    root->left=newNode(3);
    root->right=newNode(2);
    root->left->left=newNode(2);
    root->left->right=newNode(1);
    root->right->left=newNode(2);
    cout<<isSumProperty(root)<<endl; //1
    return 0;
}

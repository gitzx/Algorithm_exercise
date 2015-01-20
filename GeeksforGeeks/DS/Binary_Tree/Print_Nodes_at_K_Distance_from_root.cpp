#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=new TreeNode();
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
}

void printKDistance(TreeNode *node,int k){
    if(node==NULL){
        return;
    }
    if(k==0){
        cout<<node->data<<" ";
        return;
    }else{
        printKDistance(node->left,k-1);
        printKDistance(node->right,k-1);
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    printKDistance(root,2);
    cout<<endl; //4 5
    return 0;
}

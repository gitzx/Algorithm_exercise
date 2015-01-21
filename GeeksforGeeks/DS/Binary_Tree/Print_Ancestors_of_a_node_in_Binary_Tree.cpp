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
    return new_node;
}

bool printAncestors(TreeNode *root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(printAncestors(root->left,target)||
            printAncestors(root->right,target)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(3);
    root->right=newNode(2);
    root->left->left=newNode(2);
    printAncestors(root,2);
    cout<<endl; //3 1
    return 0;
}

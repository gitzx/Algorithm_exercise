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

bool areIdentical(TreeNode *root1,TreeNode *root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL||root2==NULL){
        return false;
    }
    return (root1->data==root2->data&&
            areIdentical(root1->left,root2->left)&&
            areIdentical(root1->right,root2->right));
}

bool isSubTree(TreeNode *T,TreeNode *S){
    if(S==NULL){
        return true;
    }
    if(T==NULL){
        return false;
    }
    if(areIdentical(T,S)){
        return true;
    }
    return isSubTree(T->left,S)||isSubTree(T->right,S);
}

int main(){
    TreeNode *T=newNode(1);
    T->left=newNode(2);
    T->right=newNode(3);
    T->left->left=newNode(4);
    TreeNode *S=newNode(2);
    S->left=newNode(4);
    cout<<isSubTree(T,S)<<endl; //1
    return 0;
}

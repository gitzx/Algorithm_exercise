#include <iostream>
#include <stdlib.h>
#include <climits>
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

TreeNode *insert(TreeNode *node,int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }else if(data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
}

int minValue(TreeNode *node){
    TreeNode *current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    return current->data;
}

int maxValue(TreeNode *node){
    TreeNode *current=node;
    while(current->right!=NULL){
        current=current->right;
    }
    return current->data;
}

int isBST(TreeNode *node){
    if(node==NULL){
        return 1;
    }
    if(node->left!=NULL&&maxValue(node->left)>node->data){
        return 0;
    }
    if(node->right!=NULL&&minValue(node->right)<node->data){
        return 0;
    }
    if(!isBST(node->left)||!isBST(node->right)){
        return 0;
    }
    return 1;
}

int isBSTUtil(TreeNode *node,int min,int max){
    if(node==NULL){
        return 1;
    }
    if(node->data<min||node->data>max){
        return 0;
    }
    return isBSTUtil(node->left,min,node->data-1)&&isBSTUtil(node->right,node->data+1,max);
}

int isBSTEfficient(TreeNode *node){
    return isBSTUtil(node,INT_MIN,INT_MAX);
}

int main(){
    TreeNode *root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(5);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    cout<<isBST(root)<<endl; //1
    cout<<isBSTEfficient(root)<<endl; //1
    return 0;
}

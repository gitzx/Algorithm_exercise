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

void printArray(int ints[],int len){
    for(int i=0;i<len;i++){
        cout<<ints[i]<<" " ;
    }
    cout<<endl;
}

void printPathsRecur(TreeNode *node,int path[],int pathLen){
    if(node==NULL){
        return;
    }
    path[pathLen]=node->data;
    pathLen++;
    if(node->left==NULL&&node->right==NULL){
        printArray(path, pathLen);
    }else{
        printPathsRecur(node->left,path,pathLen);
        printPathsRecur(node->right,path,pathLen);
    }
}

void printPaths(TreeNode *node){
    int path[1000];
    printPathsRecur(node,path,0);
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    printPaths(root);
    return 0;
}

//1 2 4
//1 2 5
//1 3

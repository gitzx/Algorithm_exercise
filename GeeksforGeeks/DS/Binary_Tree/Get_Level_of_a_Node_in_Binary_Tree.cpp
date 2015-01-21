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

int getLevelUtil(TreeNode *node, int data,int level){
    if(node==NULL){
        return 0;
    }
    if(node->data==data){
        return level;
    }
    int downlevel=getLevelUtil(node->left,data,level+1);
    if(downlevel!=0){
        return downlevel;
    }
    downlevel=getLevelUtil(node->right,data,level+1);
    return downlevel;
}

int getLevel(TreeNode *node, int data){
    return getLevelUtil(node,data,1);
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    for(int i=1;i<5;i++){
        int level=getLevel(root,i);
        if(level!=0){
            cout<<level<<" ";
        }
    }
    cout<<endl; //1 2 2 3
    return 0;
}

//Two trees are identical when they have same data and arrangement of data is also same.

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

int identicalTrees(TreeNode *node1,TreeNode *node2){
    if(node1==NULL&&node2==NULL){
        return 1;
    }
    if(node1!=NULL&&node2!=NULL){
        return node1->data==node2->data&&
            identicalTrees(node1->left,node2->left)&&
            identicalTrees(node1->right,node2->right);
    }
    return 0;
}

int main(){
    TreeNode *root1=newNode(1);
    root1->left=newNode(2);
    root1->right=newNode(3);
    TreeNode *root2=newNode(1);
    root2->left=newNode(2);
    root2->right=newNode(3);
    cout<<identicalTrees(root1,root2)<<endl; //1
    return 0;
}

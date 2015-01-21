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
    TreeNode *new_node=new TreeNode;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void getTargetLeaf(TreeNode *node,int *max_sum_ref,int curr_sum,TreeNode **target_leaf_ref){
    if(node==NULL){
        return;
    }
    curr_sum=curr_sum+node->data;
    if(node->left==NULL&&node->right==NULL){
        if(curr_sum>*max_sum_ref){
            *max_sum_ref=curr_sum;
            *target_leaf_ref=node;
        }
    }
    getTargetLeaf(node->left,max_sum_ref,curr_sum,target_leaf_ref);
    getTargetLeaf(node->right,max_sum_ref,curr_sum,target_leaf_ref);
}

bool printPath(TreeNode *root,TreeNode *target_leaf){
    if(root==NULL){
        return false;
    }
    if(root==target_leaf||printPath(root->left,target_leaf)||
            printPath(root->right,target_leaf)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int maxSumPath(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    TreeNode *target_leaf;
    int max_sum;
    getTargetLeaf(node,&max_sum,0,&target_leaf);
    printPath(node,target_leaf);
    cout<<endl;
    return max_sum;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    cout<<maxSumPath(root)<<endl;
    return 0;
}

//4 2 1
//7

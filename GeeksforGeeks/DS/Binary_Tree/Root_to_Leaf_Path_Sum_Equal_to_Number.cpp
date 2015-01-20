/*Given a binary tree and a number, return true if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given number. Return false if no such path can be found.
*/

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

int hasPathSum(TreeNode *node, int sum){
    if(node==NULL){
        return sum==0;
    }else{
        int ans=0;
        int subSum=sum-node->data;
        if(subSum==0&&node->left==NULL&&node->right==NULL){
            return 1;
        }
        if(node->left){
            ans=ans||hasPathSum(node->left,subSum);
        }
        if(node->right){
            ans=ans||hasPathSum(node->right,subSum);
        }
        return ans;
    }
}

int main(){
    int sum=4;
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    cout<<hasPathSum(root,sum)<<endl; //1
    return 0;
}

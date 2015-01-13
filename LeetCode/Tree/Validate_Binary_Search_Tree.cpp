/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    bool isValidBST(TreeNode *root){
        return isValid(root,INT_MIN,INT_MAX);
    }
    bool isValid(TreeNode *node,int MIN,int MAX){
        if(node==NULL){
            return true;
        }
        if(node->val>MIN&&node->val<MAX
                &&isValid(node->left,MIN,node->val)
                &&isValid(node->right,node->val,MAX)){
            return true;
        }else{
            return false;
        }
    }
};

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=data;
    node->left=NULL;
    node->right=NULL;
}

int main(){
    Solution solution;
    TreeNode *root=newNode(3);
    root->left=newNode(2);
    root->right=newNode(4);
    cout<<solution.isValidBST(root)<<endl; //1
    return 0;
}

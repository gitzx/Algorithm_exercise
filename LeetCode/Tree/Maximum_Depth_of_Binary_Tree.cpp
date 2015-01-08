/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//using recursive
class Solution1{
public:
    int maxDepth(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL){
            return 1+maxDepth(root->right);
        }
        if(root->right==NULL){
            return 1+maxDepth(root->left);
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int max(int a, int b){
        return a>b?a:b;
    }
};

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=data;
    node->left=NULL;
    node->right=NULL;
}

int main(){
    Solution1 solution1;
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    int max=solution1.maxDepth(root);
    cout<<max<<endl; //3
    return 0;
}

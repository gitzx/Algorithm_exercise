/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees 
of every node never differ by more than 1.
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

//usingrecursive
class Solution1{
public:
    bool isBalanced(TreeNode *root){
        if(root==NULL){
            return true;
        }
        int leftDepth=getDepth(root->left);
        int rightDepth=getDepth(root->right);
        if(abs(leftDepth-rightDepth)>1){
            return false;
        }
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int getDepth(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return 1+max(getDepth(root->left),getDepth(root->right));
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
    bool isBalanced=solution1.isBalanced(root);
    cout<<isBalanced<<endl; //1
    return 0;
}

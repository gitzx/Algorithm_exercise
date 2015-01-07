/*Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p&&!q){
            return true;
        }
        if(!p||!q){
            return false;
        }
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

TreeNode* newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=data;
    node->left=NULL;
    node->right=NULL;
}

int main(){
    Solution solution;
    TreeNode *root1=newNode(1);
    root1->left=newNode(2);
    root1->right=newNode(3);
    TreeNode *root2=newNode(1);
    root2->left=newNode(2);
    root2->right=newNode(3);
    bool isSame=solution.isSameTree(root1, root2);
    cout<<isSame<<endl;
    return 0;
}

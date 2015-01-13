/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root){
        int sum=0;
        int path=0;
        generateSum(root,sum,path);
        return sum;
    }
    void generateSum(TreeNode *root,int& sum,int path){
        if(root==NULL){
            return;
        }
        path=path*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            sum+=path;
            return;
        }
        generateSum(root->left,sum,path);
        generateSum(root->right,sum,path);
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
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<solution.sumNumbers(root)<<endl;  //262
    return 0;
}

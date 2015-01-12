/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
*/

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root){
       vector<int> result;
       inorderTra(root, result);
       return result;
    }
    void inorderTra(TreeNode* node,vector<int> &result){
        if(node==NULL){
            return;
        }
        inorderTra(node->left,result);
        result.push_back(node->val);
        inorderTra(node->right,result);
    }
};

//using Iteration
class Solution2{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<TreeNode*> sta;
        vector<int> result;
        if(root==NULL){
            return result;
        }
        TreeNode* node=root;
        while(sta.size()>0||node!=NULL){
            while(node!=NULL){
                sta.push_back(node);
                node=node->left;
            }
            node=sta.back();
            sta.pop_back();
            result.push_back(node->val);
            node=node->right;
        }
        return result;
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
    Solution2 solution2;
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    vector<int> result1=solution1.inorderTraversal(root);
    vector<int> result2=solution2.inorderTraversal(root);
    for(int i=0;i<result1.size();i++){
        cout<<result1[i]<<" ";
    }
    cout<<endl; //4 2 5 1 3
    for(int j=0;j<result2.size();j++){
        cout<<result2[j]<<" ";
    }
    cout<<endl;
    return 0; //4 2 5 1 3
}

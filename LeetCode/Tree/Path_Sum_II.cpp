/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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

class Solution{
public:
    vector<vector<int> > pathSum(TreeNode *root,int sum){
        vector<vector<int> > collection;
        vector<int> solution;
        if(root!=NULL){
            getPath(root,sum,0,solution,collection);
        }
        return collection;
    }

    void getPath(TreeNode *root,int sum,int cal,vector<int>& solution,vector<vector<int> >& collection){
        solution.push_back(root->val);
        cal+=root->val;
        if(sum==cal&&root->left==NULL&&root->right==NULL){
            collection.push_back(solution);
        }else{
            if(root->left!=NULL){
                getPath(root->left,sum,cal,solution,collection);
            }
            if(root->right!=NULL){
                getPath(root->right,sum,cal,solution,collection);
            }
        }
        solution.pop_back();
        cal-=root->val;
        return;
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
    root->left->left=newNode(6);
    root->left->right=newNode(5);
    root->right->left=newNode(4);
    vector<vector<int> > vt=solution.pathSum(root,8);
    for(int i=0;i<vt.size();++i){
        for(int j=0;j<3;++j){
            cout<<vt[i][j]<<" ";
        }
        //1 2 5
        //1 3 4
        cout<<endl;
    }
}

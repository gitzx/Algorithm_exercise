/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//DFS using recursive
class Solution1{
public:
    vector<vector<int> > levelOrder(TreeNode *root){
        vector<vector<int> > output;
        if(!root){
            return output;
        }
        vector<int> oneLine;
        bool hasNextLevel=true;
        int currentLevel = 1;
        while(hasNextLevel){
            hasNextLevel = false;
            LevelTravel(root,currentLevel,hasNextLevel,oneLine);
            output.push_back(oneLine);
            currentLevel++;
            oneLine.clear();
        }
        return output;
    }
    void LevelTravel(TreeNode *root,int level,bool& hasNextLevel,vector<int>& result){
        if(!root){
            return;
        }
        if(level==1){
            result.push_back(root->val);
            if(root->left||root->right){
                hasNextLevel = true;
            }
            return;
        }else{
            LevelTravel(root->left,level-1,hasNextLevel,result);
            LevelTravel(root->right,level-1,hasNextLevel,result);
        }    
    }
};

//BFS
class Solution2{
public:
    vector<vector<int> > levelOrder(TreeNode *root){
       vector<vector<int> > result;
       vector<TreeNode*> sta;
       if(root==NULL){
           return result;
       }
       sta.push_back(root);
       int nextLevelCount=1;
       int index=0;
       while(index<sta.size()){
           int curLevelCount = nextLevelCount;
           nextLevelCount = 0;
           vector<int> level;
           for(int i=index;i<index+curLevelCount;++i){
               root=sta[i];
               level.push_back(root->val);
               if(root->left!=NULL){
                   sta.push_back(root->left);
                   nextLevelCount++;
               }
               if(root->right!=NULL){
                   sta.push_back(root->right);
                   nextLevelCount++;
               }
           }
           result.push_back(level);
           index=index+curLevelCount;
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
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    vector<vector<int> > result=solution1.levelOrder(root);
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[i].size();++j){
            cout<<result[i][j]<<" ";
        }
        //1
        //2 3
        //4 5
        cout<<endl;
    }
    return 0;
}

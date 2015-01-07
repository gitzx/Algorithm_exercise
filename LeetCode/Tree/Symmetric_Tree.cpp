/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

//using recursive
class Solution1{
public:
    bool isSymmetric(TreeNode *root){
        if(root==NULL){
            return true;
        }
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode *left, TreeNode *right){
        if(left==NULL){
            return right==NULL;
        }
        if(right==NULL){
            return left==NULL;
        }
        if(left->val!=right->val){
            return false;
        }
        if(!isSym(left->left, right->right)){
            return false;
        }
        if(!isSym(left->right, right->left)){
            return false;
        }
        return true;
    }
};

//using non-recursive
class Solution2{
public:
    bool isSymmetric(TreeNode *root){
        if(root==NULL){
            return true;
        }
        vector<TreeNode*> queue;
        queue.push_back(root);
        int curLevel=1;
        while(curLevel>0){
            int i=0;
            while(i<curLevel){
                TreeNode* p=queue[i];
                i++;
                if(p==NULL){
                    continue;
                }
                queue.push_back(p->left);
                queue.push_back(p->right);
            }
            int start=0, end=curLevel-1;
            while(start<end){
                TreeNode* pl=queue[start];
                TreeNode* pr=queue[end];
                int l=pl==NULL?-1:pl->val;
                int r=pr==NULL?-1:pr->val;
                if(l!=r){
                    return false;
                }
                start++;
                end--;
            }
            queue.erase(queue.begin(),queue.begin()+curLevel);
            curLevel=queue.size();
        }
        return true;
    }
};

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
}

int main(){
    Solution1 solution1;
    Solution2 solution2;
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(2);
    root->left->right=newNode(3);
    root->right->right=newNode(3);
    bool isSymmetric1=solution1.isSymmetric(root);
    cout<<isSymmetric1<<endl; //0
    bool isSymmetric2=solution2.isSymmetric(root);
    cout<<isSymmetric2<<endl; //0
    return 0;
}

/*Binary Tree Operations:
 (1)Inorder Traversal
 (2)Preorder Traversal
 (3)PostOrder Traversal
 (4)LevelOrder Traversal
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

TreeNode *newNode(int data){
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->val=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//using recursive
//Inorder Traversal
void inorderTraversal(TreeNode *node){
    if(node==NULL){
        return;
    }
    inorderTraversal(node->left);
    cout<<node->val<<" ";
    inorderTraversal(node->right);
}

//Preorder Traversal
void preorderTraversal(TreeNode *node){
    if(node==NULL){
        return;
    }
    cout<<node->val<<" ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

//Postorder Traversal
void postorderTraversal(TreeNode *node){
    if(node==NULL){
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<node->val<<" ";
}

//LevelOrder Traversal
int height(TreeNode *node){
    if(node==NULL){
        return 0;
    }else{
        int lheight=height(node->left);
        int rheight=height(node->right);
        if(lheight>rheight){
            return lheight+1;
        }else{
            return rheight+1;
        }
    }
}
void printGivenLevel(TreeNode *root,int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->val<<" ";
    }else if(level>1){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
void printLevelOrder(TreeNode *root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printGivenLevel(root,i);
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    inorderTraversal(root);
    cout<<endl; //4 2 5 1 3
    preorderTraversal(root);
    cout<<endl; //1 2 4 5 3
    postorderTraversal(root);
    cout<<endl; //4 5 2 3 1
    printLevelOrder(root);
    cout<<endl; //1 2 3 4 5
    return 0;
}


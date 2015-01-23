/*Given a Binary Tree and a positive integer k, print all nodes that are distance k from a leaf node.
Here k distance from a leaf means k levels higher than a leaf node.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=new TreeNode;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void kDistantFromLeafUtil(TreeNode *node,int path[],bool visited[],int pathLen,int k){
    if(node==NULL){
        return;
    }
    path[pathLen]=node->data;
    visited[pathLen]=false;
    pathLen++;
    if(node->left==NULL&&node->right==NULL&&pathLen-k-1>=0&&visited[pathLen-k-1]==false){
        cout<<path[pathLen-k-1]<<" ";
        visited[pathLen-k-1]=true;
        return;
    }
    kDistantFromLeafUtil(node->left,path,visited,pathLen,k);
    kDistantFromLeafUtil(node->right,path,visited,pathLen,k);
}

void printkDistantFromLeaf(TreeNode *node, int k){
    int path[1000];
    bool visited[1000]={false};
    kDistantFromLeafUtil(node,path,visited,0,k);
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    printkDistantFromLeaf(root,2); //1 3
    cout<<endl;
    return 0;
}

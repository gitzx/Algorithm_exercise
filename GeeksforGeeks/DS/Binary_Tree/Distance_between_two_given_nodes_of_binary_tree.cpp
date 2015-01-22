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

int findLevel(TreeNode *root,int data,int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==data){
        return 1;
    }
    int llevel=findLevel(root->left,data,level+1);
    return (llevel!=-1)?1:findLevel(root->right,data,level+1);
}

TreeNode *findDistUtil(TreeNode *root,int n1,int n2,int &d1,int &d2,int &dist,int level){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1){
        d1=level;
        return root;
    }
    if(root->data==n2){
        d2=level;
        return root;
    }
    TreeNode *left_lca=findDistUtil(root->left,n1,n2,d1,d2,dist,level+1);
    TreeNode *right_lca=findDistUtil(root->right,n1,n2,d1,d2,dist,level+1);
    if(left_lca&&right_lca){
        dist=d1+d2-2*level;
        return root;
    }
    return (left_lca!=NULL)?left_lca:right_lca;
}

int findDistance(TreeNode *root,int n1,int n2){
    int d1=-1,d2=-1,dist;
    TreeNode *lca=findDistUtil(root,n1,n2,d1,d2,dist,1);
    if(d1!=-1&&d2!=-1){
        return dist;
    }
    if(d1!=-1){
        dist=findLevel(lca,n2,0);
        return dist;
    }
    if(d2!=-1){
        dist=findLevel(lca,n1,0);
        return dist;
    }
    return -1;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<findDistance(root,2,3)<<endl; //2
    cout<<findDistance(root,4,3)<<endl; //3
    cout<<findDistance(root,4,5)<<endl; //2
    return 0;
}

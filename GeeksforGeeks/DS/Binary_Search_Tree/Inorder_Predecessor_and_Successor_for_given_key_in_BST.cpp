#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left,*right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

TreeNode *insert(TreeNode *node,int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }else{
        node->right=insert(node->right,data);
    }
    return node;
}

void findPreSuc(TreeNode *root,TreeNode *&pre,TreeNode *&suc,int data){
    if(root==NULL){
        return;
    }
    if(root->data==data){
        if(root->left!=NULL){
            TreeNode *temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            pre=temp;
        }
        if(root->right!=NULL){
            TreeNode *temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            suc=temp;
        }
        return;
    }
    if(root->data>data){
        suc=root;
        findPreSuc(root->left,pre,suc,data);
    }else{
        pre=root;
        findPreSuc(root->right,pre,suc,data);
    }
}

int main(){
    TreeNode *root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    insert(root,6);
    insert(root,9);
    TreeNode *pre,*suc;
    findPreSuc(root,pre,suc,8);
    if(pre!=NULL){
        cout<<pre->data<<endl; //7
    }
    if(suc!=NULL){
        cout<<suc->data<<endl; //9
    }
    return 0;
}


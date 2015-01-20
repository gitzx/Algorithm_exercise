#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int data){
    TreeNode *new_node=new TreeNode();
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

int height(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    int lheight=height(node->left);
    int rheight=height(node->right);
    if(lheight>rheight){
        return lheight+1;
    }else{
        return rheight+1;
    }
}

int getWidth(TreeNode *node,int level){
    if(node==NULL){
        return 0;
    }
    if(level==1){
        return 1;
    }else{
        return getWidth(node->left,level-1)+getWidth(node->right,level-1);
    }
}

int getMaxWidth(TreeNode *node){
    int h=height(node);
    int maxWidth=0;
    int width;
    for(int i=0;i<=h;i++){
        width=getWidth(node,i);
        if(width>maxWidth){
            maxWidth=width;
        }
    }
    return maxWidth;
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    cout<<getMaxWidth(root)<<endl; //3
    return 0;
}

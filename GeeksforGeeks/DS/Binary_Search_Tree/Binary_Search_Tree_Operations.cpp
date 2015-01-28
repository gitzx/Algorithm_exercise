//Binary Search Tree Operations:
//(1)search
//(2)insertion
//(3)delete

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
    new_node->left=new_node->right=NULL;
    return new_node;
}

void inorderTraversal(TreeNode *node){
    if(node==NULL){
        return;
    }
    inorderTraversal(node->left);
    cout<<node->data<<" ";
    inorderTraversal(node->right);
}

//search
TreeNode *search(TreeNode *root,int data){
    if(root==NULL||root->data==data){
        return root;
    }
    if(root->data<data){
        return search(root->right,data);
    }
    return search(root->left,data);
}

//insertion
TreeNode *insert(TreeNode *node,int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }else if(data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
}

//delete
TreeNode *minValueNode(TreeNode *node){
    TreeNode *current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

TreeNode *deleteNode(TreeNode *root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=deleteNode(root->left,data);
    }else if(data>root->data){
        root->right=deleteNode(root->right,data);
    }else{
        if(root->left==NULL){
            TreeNode *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            TreeNode *temp=root->left;
            free(root);
            return temp;
        }
        TreeNode *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
    TreeNode *root=NULL;
    root=insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    inorderTraversal(root);
    cout<<endl; //1 2 3 4 5 6 7
    TreeNode *node=search(root,3);
    cout<<node->data<<endl; //3
    deleteNode(root,4);
    inorderTraversal(root);
    cout<<endl; //1 2 3 5 6 7
    return 0;
}

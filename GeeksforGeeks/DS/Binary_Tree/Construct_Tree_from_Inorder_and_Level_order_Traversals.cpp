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

int search(int arr[],int start,int end,int value){
    for(int i=start;i<=end;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}

//获取左右子树的值数组
int *getChildrenKeys(int in[],int level[],int m,int n){
    int *newLevel=new int[m];
    int j=0;
    for(int i=0;i<n;i++){
        if(search(in,0,m-1,level[i])!=-1){
            newLevel[j]=level[i];
            j++;
        }
    }
    return newLevel;
}

TreeNode *buildTree(int in[],int level[],int inStart,int inEnd,int n){
    if(inStart>inEnd){
        return NULL;
    }
    TreeNode *root=newNode(level[0]);
    if(inStart==inEnd){
        return root;
    }
    int inIndex=search(in,inStart,inEnd,root->data);
    int *leftLevel=getChildrenKeys(in,level,inIndex,n);
    int *rightLevel=getChildrenKeys(in+inIndex+1,level,n-inIndex-1,n);
    root->left=buildTree(in,leftLevel,inStart,inIndex-1,n);
    root->right=buildTree(in,rightLevel,inIndex+1,inEnd,n);
    delete[] leftLevel;
    delete[] rightLevel;
    return root;
}

void inorderTraversal(TreeNode *root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n=sizeof(in)/sizeof(in[0]);
    TreeNode *root=buildTree(in,level,0,n-1,n);
    inorderTraversal(root);
    cout<<endl; //4 8 10 12 14 20 22
    return 0;
}

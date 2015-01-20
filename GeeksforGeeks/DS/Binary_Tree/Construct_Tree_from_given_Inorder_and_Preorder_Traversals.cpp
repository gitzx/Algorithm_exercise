#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    char data;
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

void inorderTraversal(TreeNode *node){
    if(node==NULL){
        return;
    }
    inorderTraversal(node->left);
    cout<<node->data<<" ";
    inorderTraversal(node->right);
}

int search(char arr[],int start,int end, char value){
    int i;
    for(i=start;i<=end;i++){
        if(arr[i]==value){
            return i;
        }
    }
}

TreeNode *buildTree(char in[],char pre[],int inStart, int inEnd){
    static int preIndex=0;
    if(inStart>inEnd){
        return NULL;
    }
    TreeNode *root=newNode(pre[preIndex++]);
    if(inStart==inEnd){
        return root;
    }
    int inIndex=search(in,inStart,inEnd,root->data);
    root->left=buildTree(in,pre,inStart,inIndex-1);
    root->right=buildTree(in,pre,inIndex+1,inEnd);
    return root;
}

int main(){
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len=sizeof(in)/sizeof(in[0]);
    TreeNode *root=buildTree(in, pre,0,len-1);
    inorderTraversal(root);
    cout<<endl;
    return 0;
}

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

void inorder(TreeNode *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

struct StackNode{
    TreeNode *t;
    StackNode *next;
};

void push(StackNode **s,TreeNode *t){
    StackNode *new_node=(StackNode*)malloc(sizeof(StackNode));
    new_node->t=t;
    new_node->next=*s;
    *s=new_node;
}

TreeNode *pop(StackNode **s){
    TreeNode *t;
    StackNode *st;
    st=*s;
    *s=(*s)->next;
    t=st->t;
    free(st);
    return t;
}

int isEmpty(StackNode *s){
    if(s==NULL){
        return 1;
    }
    return 0;
}

void merge(TreeNode *root1,TreeNode *root2){
    TreeNode *current1=root1;
    TreeNode *current2=root2;
    StackNode *s1=NULL;
    StackNode *s2=NULL;
    if(root1==NULL){
        inorder(root2);
        return;
    }
    if(root2==NULL){
        inorder(root1);
        return;
    }
    while(current1!=NULL||!isEmpty(s1)||current2!=NULL||!isEmpty(s2)){
        if(current1!=NULL||current2!=NULL){
            if(current1!=NULL){
                push(&s1,current1);
                current1=current1->left;
            }
            if(current2!=NULL){
                push(&s2,current2);
                current2=current2->left;
            }
        }else{
            if(isEmpty(s1)){
                while(!isEmpty(s2)){
                    current2=pop(&s2);
                    current2->left=NULL;
                    inorder(current2);
                }
                return;
            }
            if(isEmpty(s2)){
                while(!isEmpty(s1)){
                    current1=pop(&s1);
                    current1->left=NULL;
                    inorder(current1);
                }
                return;
            }
            current1=pop(&s1);
            current2=pop(&s2);
            if(current1->data<current2->data){
                cout<<current1->data<<" ";
                current1=current1->right;
                push(&s2,current2);
                current2=NULL;
            }else{
                cout<<current2->data<<" ";
                current2=current2->right;
                push(&s1,current1);
                current1=NULL;
            }
        }
    }
}

int main(){
    TreeNode *root1=NULL;
    TreeNode *root2=NULL;
    root1=newNode(3);
    root1->left=newNode(1);
    root1->right=newNode(5);
    root2=newNode(4);
    root2->left=newNode(2);
    root2->right=newNode(6);
    merge(root1,root2); //1 2 3 4 5 6
    cout<<endl;
    return 0;
}

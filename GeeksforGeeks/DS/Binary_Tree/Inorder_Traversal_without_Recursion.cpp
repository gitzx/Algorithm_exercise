#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

struct StackNode{
    TreeNode *t;
    StackNode *next;
};

bool isEmpty(StackNode *top){
    return (top==NULL)?1:0;
}

void push(StackNode **top_ref, TreeNode *node){
    StackNode *new_stackNode=(StackNode*)malloc(sizeof(StackNode));
    if(new_stackNode==NULL){
        cout<<"stack overflow"<<endl;
    }
    new_stackNode->t=node;
    new_stackNode->next=(*top_ref);
    (*top_ref)=new_stackNode;
}

TreeNode *pop(StackNode **top_ref){
    TreeNode *treeNode;
    StackNode *top;
    if(isEmpty(*top_ref)){
        cout<<"Stack UnderFlow"<<endl;
    }else{
        top=*top_ref;
        treeNode=top->t;
        *top_ref=top->next;
        free(top);
        return treeNode;
    }
}

TreeNode *newNode(int data){
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

//using stack without recursion
void inorder(TreeNode *root){
    TreeNode *current=root;
    StackNode *stack=NULL;
    bool done=0;
    while(!done){
        if(current!=NULL){
            push(&stack,current);
            current=current->left;
        }else{
            if(!isEmpty(stack)){
                current=pop(&stack);
                cout<<current->data<<" ";
                current=current->right;
            }else{
                cout<<endl;
                done=1;
            }
        }
    }
}

int main(){
    TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    inorder(root); //4 2 5 1 3
    return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

struct Node{
    int data;
    Node *next;
};

TreeNode *newNode(int data){
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void preOrder(TreeNode *node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int coutNodes(Node *head){
    int count=0;
    Node *temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

TreeNode *sortedListToBSTRecur(Node **head_ref,int n){
   if(n<=0){
       return NULL;
   } 
   TreeNode *left=sortedListToBSTRecur(head_ref,n/2);
   TreeNode *root=newNode((*head_ref)->data);
   root->left=left;
   *head_ref=(*head_ref)->next;
   root->right=sortedListToBSTRecur(head_ref,n-n/2-1);
   return root;
}

TreeNode *sortedListToBST(Node *head){
    int n=coutNodes(head);
    return sortedListToBSTRecur(&head,n);
}

int main(){
    Node *head=NULL;
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head); //1 2 3 4 5 6 7
    TreeNode *root=sortedListToBST(head);
    preOrder(root);
    cout<<endl; //4 2 1 3 6 5 7 
    return 0;
}

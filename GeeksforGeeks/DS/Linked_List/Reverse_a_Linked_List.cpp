#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//using iterator
void reverse(Node** head_ref){
    Node *prev=NULL;
    Node *cur=*head_ref;
    Node *next;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head_ref=prev;
}

//using recursive
void recursiveReverse(Node **head_ref){
    Node *first;
    Node *rest;
    if(*head_ref==NULL){
        return;
    }
    first=*head_ref;
    rest=first->next;
    if(rest==NULL){
        return;
    }
    recursiveReverse(&rest);
    first->next->next=first;
    first->next=NULL;
    *head_ref=rest;
}

void push(Node **head_ref, int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void printList(Node *head_ref){
    Node *temp=head_ref;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *node=NULL;
    push(&node,1);
    push(&node,2);
    push(&node,3);
    push(&node,4);
    reverse(&node);
    printList(node); //1 2 3 4
    recursiveReverse(&node);
    printList(node); //4 3 2 1
    return 0;
}


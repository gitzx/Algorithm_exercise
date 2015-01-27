#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

//add node at the front
void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    new_node->prev=NULL;
    if(*head_ref!=NULL){
        (*head_ref)->prev=new_node;
    }
    *head_ref=new_node;
}

//add node at the end
void append(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    Node *last=*head_ref;
    new_node->data=data;
    new_node->next=NULL;
    if(*head_ref==NULL){
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    new_node->prev=last;
    return;
}

//add a node after a given node
void insertAfter(Node *prev_node,int data){
    if(prev_node==NULL){
        return;
    }
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
    new_node->prev=prev_node;
    if(new_node->next!=NULL){
        new_node->next->prev=new_node;
    }
}

void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    append(&head,3);
    append(&head,4);
    insertAfter(head->next,5);
    printList(head); //2 1 5 3 4
    return 0;
}

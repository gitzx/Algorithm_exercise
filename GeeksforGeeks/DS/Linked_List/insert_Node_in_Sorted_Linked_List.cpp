#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *newNode(int data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(Node **head_ref,int data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void sortedInsert(Node **head_ref,Node *new_node){
    Node *current;
    if(*head_ref==NULL||(*head_ref)->data>=new_node->data){
        new_node->next=*head_ref;
        *head_ref=new_node;
    }else{
        current=*head_ref;
        while(current->next!=NULL&&current->next->data<new_node->data){
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}

void printList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,1);
    push(&head,0);
    printList(head); //0 1 3 4 5
    Node *new_node=newNode(2);
    sortedInsert(&head,new_node);
    printList(head); //0 1 2 3 4 5 
    return 0;
}

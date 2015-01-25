#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));;
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void removeDuplicates(Node *head){
    Node *current=head;
    Node *next_next;
    if(current==NULL){
        return;
    }
    while(current->next!=NULL){
        if(current->data==current->next->data){
            next_next=current->next->next;
            free(current->next);
            current->next=next_next;
        }else{
            current=current->next;
        }
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
    push(&head,3);
    push(&head,3);
    push(&head,3);
    push(&head,4);
    printList(head); //4 3 3 3 2 1
    removeDuplicates(head);
    printList(head); //4 3 2 1
    return 0;
}

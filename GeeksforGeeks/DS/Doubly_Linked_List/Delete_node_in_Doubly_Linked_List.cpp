#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=*head_ref;
    if(*head_ref!=NULL){
        (*head_ref)->prev=new_node;
    }
    *head_ref=new_node;
}

void deleteNode(Node **head_ref,Node *del){
    if(*head_ref==NULL||del==NULL){
        return;
    }
    if(*head_ref==del){
        *head_ref=del->next;
    }
    if(del->next!=NULL){
        del->next->prev=del->prev;
    }
    if(del->prev!=NULL){
        del->prev->next=del->next;
    }
    free(del);
    return;
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
    push(&head,4);
    printList(head); //4 3 2 1
    deleteNode(&head,head);
    deleteNode(&head,head->next);
    printList(head); //3 1
    return 0;
}

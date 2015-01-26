#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head_ref,int data){
    Node *ptr1=(Node*)malloc(sizeof(Node));
    Node *temp=*head_ref;
    ptr1->data=data;
    ptr1->next=*head_ref;
    if(*head_ref!=NULL){
        while(temp->next!=*head_ref){
            temp=temp->next;
        }
        temp->next=ptr1;
    }else{
        ptr1->next=ptr1;
    }
    *head_ref=ptr1;
}

void printList(Node *head){
    Node *temp=head;
    if(head!=NULL){
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
    cout<<endl;
}

int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    printList(head); //5 4 3 2 1
    return 0;
}

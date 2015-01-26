/*Given a Singly Linked List, starting from the second node delete all alternate nodes of it. 
For example, if the given linked list is 1->2->3->4->5 then your function should convert it to 1->3->5, 
and if the given linked list is 1->2->3->4 then convert it to 1->3.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

//using recursive
void deleteAltByRecursive(Node *head){
    if(head==NULL){
        return;
    }
    Node *node=head->next;
    if(node==NULL){
        return;
    }
    head->next=node->next;
    free(node);
    deleteAltByRecursive(head->next);
}

//using Iterative
void deleteAltByIterative(Node *head){
    if(head==NULL){
        return;
    }
    Node *prev=head;
    Node *node=head->next;
    while(prev!=NULL&&node!=NULL){
        prev->next=node->next;
        free(node);
        prev=prev->next;
        if(prev!=NULL){
            node=prev->next;
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
    Node *head1=NULL;
    Node *head2=NULL;
    push(&head1,5);
    push(&head1,4);
    push(&head1,3);
    push(&head1,2);
    push(&head1,1);
    push(&head2,5);
    push(&head2,4);
    push(&head2,3);
    push(&head2,2);
    push(&head2,1);
    printList(head1); //1 2 3 4 5 
    deleteAltByRecursive(head1);
    printList(head1); //1 3 5
    deleteAltByIterative(head2);
    printList(head2); //1 3 5
    return 0;
}

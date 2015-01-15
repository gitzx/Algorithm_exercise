/*
Linked List Operations:
(1)Traversal
(2)Insertion
(3)Deletion
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//Traversal
void traversalList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

//Insertion
//(1)insert a new node at the front of the linked list
void push(Node **head_ref, int new_data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
//(2)insert a new node after a given node
void insertAfter(Node *prev_node, int new_data){
    if(prev_node==NULL){
        return;
    }
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
//(3)insert a new node at the end of the linked list
void append(Node **head_ref, int new_data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=new_data;
    Node *last=*head_ref;
    new_node->next=NULL;
    if((*head_ref)==NULL){
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
} 

//Deletion
void deleteNode(Node **head_ref,int key){
    Node *temp=*head_ref, *prev;
    if(temp!=NULL&&temp->data==key){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

int main(){
        Node *head=NULL;
        append(&head,6);
        push(&head,7);
        push(&head,1);
        insertAfter(head->next,8);
        deleteNode(&head,7);
        traversalList(head);
        return 0;
}

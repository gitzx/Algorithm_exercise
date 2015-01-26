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
bool areIdenticalByRecursive(Node *head1,Node *head2){
    if(head1==NULL&&head2==NULL){
        return 1;
    }
    if(head1==NULL&&head2!=NULL){
        return 0;
    }
    if(head1!=NULL&&head2==NULL){
        return 0;
    }
    if(head1->data!=head2->data){
        return 0;
    }
    areIdenticalByRecursive(head1->next,head2->next);
}

//using iterative
bool areIdenticalByIterative(Node *head1,Node *head2){
    while(1){
        if(head1==NULL&&head2==NULL){
            return 1;
        }
        if(head1==NULL&&head2!=NULL){
            return 0;
        }
        if(head1!=NULL&&head2==NULL){
            return 0;
        }
        if(head1->data!=head2->data){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
}

int main(){
    Node *head1=NULL;
    Node *head2=NULL;
    push(&head1,3);
    push(&head1,2);
    push(&head1,1);
    push(&head2,3);
    push(&head2,2);
    push(&head2,1);
    cout<<areIdenticalByRecursive(head1,head2)<<endl; //1
    cout<<areIdenticalByIterative(head1,head2)<<endl; //1
    return 0;
}

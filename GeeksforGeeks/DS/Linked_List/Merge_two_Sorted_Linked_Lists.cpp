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
Node * sortedMergeRecursive(Node *head1,Node *head2){
    Node *result=NULL;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        result=head1;
        result->next=sortedMergeRecursive(head1->next,head2);
    }else{
        result=head2;
        result->next=sortedMergeRecursive(head1,head2->next);
    }
    return result;
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
    push(&head1,5);
    push(&head1,3);
    push(&head1,1);
    Node *head2=NULL;
    push(&head2,4);
    push(&head2,2);
    push(&head2,0);
    Node *result=sortedMergeRecursive(head1,head2);
    printList(result); //0 1 2 3 4 5
    return 0;
}

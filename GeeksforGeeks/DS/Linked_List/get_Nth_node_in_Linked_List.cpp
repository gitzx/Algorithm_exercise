#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head_ref,int data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

int getNth(Node *head,int index){
    Node *current=head;
    int count=0;
    while(current!=NULL){
        if(count==index){
            return current->data;
        }
        count++;
        current=current->next;
    }
    return -1;
}

int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    cout<<getNth(head,3)<<endl; //1
    return 0;
}

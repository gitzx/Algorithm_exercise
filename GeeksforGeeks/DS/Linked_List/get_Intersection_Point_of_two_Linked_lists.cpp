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

int getCount(Node *head){
    Node *current=head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

int getIntesection(int d,Node *head1,Node *head2){
    Node *current1=head1;
    Node *current2=head2;
    for(int i=0;i<d;i++){
        if(current1==NULL){
            return -1;
        }
        current1=current1->next;
    }
    while(current1!=NULL&&current2!=NULL){
        if(current1==current2){
            return current1->data;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return -1;
}

int getIntesectionNode(Node *head1,Node *head2){
    int c1=getCount(head1);
    int c2=getCount(head2);
    int d;
    if(c1>c2){
        d=c1-c2;
        return getIntesection(d,head1,head2);
    }else{
        d=c2-c1;
        return getIntesection(d,head1,head2);
    }
}

int main(){
    Node *head1=NULL;
    push(&head1,4);
    push(&head1,3);
    push(&head1,2);
    push(&head1,1);
    Node *head2=head1;
    push(&head1,1);
    push(&head2,0);
    cout<<getIntesectionNode(head1,head2)<<endl; //1
    return 0;
}

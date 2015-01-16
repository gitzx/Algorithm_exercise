#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//using the node counts
int getCount(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int getIntesection(int d,Node *head1,Node *head2){
    Node *temp1=head1;
    Node *temp2=head2;
    for(int i=0;i<d;i++){
        if(temp1==NULL){
            return -1;
        }
        temp1=temp1->next;
    }
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
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
        return getIntesection(d,head2,head1);
    }
}

void push(Node **head_ref,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

int main(){
    Node *head1, *head2;
    push(&head1,1);
    push(&head1,2);
    push(&head1,3);
    head2=head1;
    push(&head1,4);
    push(&head2,5);
    cout<<getIntesectionNode(head1,head2)<<endl; //3
    return 0;
}

//use two loops
//mark visited nodes
//Traverse both lists and compare addresses of last node
//make circle in first list
//reverse the first list and make equations

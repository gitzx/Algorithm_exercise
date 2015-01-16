#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//using two points
int detectLoop(Node *list){
    Node *ps=list;
    Node *pf=list;
    while(ps&&pf&&pf->next){
        ps=ps->next;
        pf=pf->next->next;
        if(ps==pf){
            cout<<"loop exists!"<<endl;
            return 1;
        }
    }
    return 0;
}

void push(Node **head_ref, int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    head->next->next->next->next=head;
    detectLoop(head); //loop exists!
    return 0;
}

//using hashing
//mark visited nodes

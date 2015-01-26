#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void sortedInsert(Node **head_ref,Node *new_node){
    Node *current=*head_ref;
    if(current==NULL){
        new_node->next=new_node;
        *head_ref=new_node;
    }else if(current->data>=new_node->data){
        while(current->next!=*head_ref){
            current=current->next;
        }
        current->next=new_node;
        new_node->next=*head_ref;
        *head_ref=new_node;
    }else{
        while(current->next!=*head_ref&&current->next->data<new_node->data){
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}

void printList(Node *start){
    Node *temp;
    if(start!=NULL){
        temp=start;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=start);
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    int list_size,i;
    Node *start=NULL;
    Node *temp;
    for(i=0;i<5;i++){
        temp=(Node*)malloc(sizeof(Node));
        temp->data=arr[i];
        sortedInsert(&start,temp);
    }
    printList(start); //1 2 3 4 5
    return 0;
}

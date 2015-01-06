/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//using recursion
class Solution1{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *result = NULL;
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l1->val<=l2->val){
            result=l1;
            result->next=mergeTwoLists(l1->next, l2);
        }else{
            result=l2;
            result->next=mergeTwoLists(l1, l2->next);
        }
        return result;
    }
};

class Solution2{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
       if(l1==NULL){
           return l2;
       } 
       if(l2==NULL){
           return l1;
       }
       ListNode *head = new ListNode(-1);
       ListNode *p = head;
       while(l1!=NULL&&l2!=NULL){
           if(l1->val<=l2->val){
               p->next = l1;
               l1 = l1->next;
           }else{
               p->next = l2;
               l2 = l2->next;
           }
           p = p->next;
       }
       if(l1!=NULL){
           p->next = l1;
       }
       if(l2!=NULL){
           p->next = l2;
       }
       p = head->next;
       delete head;
       return p;
    }
};

void push(ListNode **head_ref,int new_data){
    ListNode *new_node=(ListNode*)malloc(sizeof(ListNode));
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(){
    Solution1 solution1;
    Solution2 solution2;
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head3 = NULL;
    ListNode *head4 = NULL;
    ListNode *head_new1 = NULL;
    ListNode *head_new2 = NULL;
    push(&head1, 7);
    push(&head1, 5);
    push(&head1, 3);
    push(&head1, 1);
    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 2);
    push(&head3, 7);
    push(&head3, 5);
    push(&head3, 3);
    push(&head3, 1);
    push(&head4, 8);
    push(&head4, 6);
    push(&head4, 4);
    push(&head4, 2);
    head_new1 = solution1.mergeTwoLists(head1, head2);
    head_new2 = solution2.mergeTwoLists(head3, head4);
    while(head_new1!=NULL){
        cout<<head_new1->val<<" ";
        head_new1 = head_new1->next;
    }
    cout<<endl; //1 2 3 4 5 6 7 8
    while(head_new2!=NULL){
        cout<<head_new2->val<<" ";
        head_new2 = head_new2->next;
    }
    cout<<endl; //1 2 3 4 5 6 7 8 
    return 0;
}

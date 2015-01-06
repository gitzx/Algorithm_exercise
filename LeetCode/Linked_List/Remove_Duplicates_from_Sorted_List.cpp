/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(head==NULL){
            return NULL;
        }
        ListNode *pre = head;
        ListNode *p = pre->next;
        while(p!=NULL){
            if(pre->val==p->val){
                ListNode *tmp = p;
                p = p->next;
                pre->next = p;
                delete tmp;
                continue;
            }
            pre = pre->next;
            p = p->next;
        }
        return head;
    }

    void push(ListNode **head_ref, int new_data){
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
};

int main(){
    Solution solution;
    ListNode* head = NULL;
    ListNode* head_new = NULL;
    solution.push(&head, 1);
    solution.push(&head, 1);
    solution.push(&head, 2);
    solution.push(&head, 3);
    solution.push(&head, 3);
    head_new = solution.deleteDuplicates(head);
    while(head_new!=NULL){
        cout<<head_new->val<<" ";
        head_new = head_new->next;
    }
    cout<<endl; //3 2 1
    return 0;
}

/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
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
    ListNode *removeNthFromEnd(ListNode *head,int n){
        assert(head);
        ListNode *pre, *cur;
        int step = 0;
        pre = head;
        cur = head;
        while(step<n&&cur!=NULL){
            cur = cur->next;
            step++;
        }
        if(step==n&&cur==NULL){
            head=head->next;
            delete pre;
            return head;
        }
        while(cur->next!=NULL){
            pre=pre->next;
            cur=cur->next;
        }
        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return head;
    }

    void push(ListNode **head_ref, int new_data){
        ListNode* new_node=(ListNode*)malloc(sizeof(ListNode));
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
    solution.push(&head, 2);
    solution.push(&head, 3);
    solution.push(&head, 4);
    solution.push(&head, 5);
    head_new = solution.removeNthFromEnd(head, 2);
    while(head_new!=NULL){
        cout<<head_new->val<<" ";
        head_new = head_new->next;
    }
    cout<<endl; //5 4 3 1
    return 0;
}

/*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *pa=headA, *pb=headB;
        int lenA=0, lenB=0;
        while(pa){
            pa=pa->next;
            lenA++;
        }
        while(pb){
            pb=pb->next;
            lenB++;
        }
        if(lenA<=lenB){
            int len=lenA-lenB;
            pa=headA;
            pb=headB;
            while(len){
                pa=pa->next;
                len--;
            }
        }else{
            int len=lenB-lenA;
            pa=headA;
            pb=headB;
            while(len){
                pb=pb->next;
                len--;
            }
        }
        while(pa!=pb){
            pa=pa->next;
            pb=pb->next;
        }
        return pa;
    }
};

void push(ListNode **head_ref, int new_data){
    ListNode *new_node=(ListNode*)malloc(sizeof(ListNode));
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(){
    Solution solution;
    ListNode *head1=NULL;
    ListNode *head2=NULL;
    ListNode *head_new = NULL;
    int n1=1,n2=2,n3=3;
    push(&head1,n3);
    push(&head1,n2);
    push(&head1,n1);
    head2=head1;
    head_new=solution.getIntersectionNode(head1, head2);
    cout<<head_new->val<<endl; //1
    return 0;
}

/*
There are many solutions to this problem:

Brute-force solution (O(mn) running time, O(1) memory):
For each node ai in list A, traverse the entire list B and check if any node in list B coincides with ai.

Hashset solution (O(n+m) running time, O(n) or O(m) memory):
Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list B: if bi appears in the hash set, then bi is the intersection node.

Two pointer solution (O(n+m) running time, O(1) memory):
Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
If at any point pA meets pB, then pA/pB is the intersection node.
To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6),
pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly 2 more nodes than pA would.
So in the second iteration, they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, 
then the two lists have no intersections.
*/
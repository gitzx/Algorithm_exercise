'''
Write a program to find the node at which the intersection of two singly linked lists begins.


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

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def getIntersectionNode(self, headA, headB):
		if headA is None or headB is None:
			return None
		lengthA = lengthB = 0
		tempHeadA = headA
		tempHeadB = headB
		while tempHeadA:
			lengthA += 1
			tempHeadA = tempHeadA.next
		while tempHeadB:
			lengthB += 1
			tempHeadB = tempHeadB.next
		if tempHeadA != tempHeadB:
			return None
		if lengthA - lengthB >0: 
			for l in range(lengthA-lengthB):
				headA = headA.next
		if lengthB - lengthA > 0:
			for l in range(lengthB-lengthA):
				headB = headB.next
		while headA != headB:
			headA = headA.next
			headB = headB.next
		return headA







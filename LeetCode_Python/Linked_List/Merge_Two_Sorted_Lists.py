'''
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def mergeTwoLists(self, l1, l2):
		if l1 is None and l2 is None:
			return None
		dummy = ListNode(0)
		tempNode = dummy
		while l1 and l2:
			if l1.val < l2.val:
				tempNode.next = l1
				l1 = l1.next
			else:
				tempNode.next = l2
				l2 = l2.next
			tempNode = tempNode.next
		if l1:
			tempNode.next = l1
		else:
			tempNode.next = l2
		return dummy.next

			

'''
Reverse a singly linked list.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def reverseList(self, head):
		dummy = ListNode(0)
		while head:
			next = head.next
			head.next = dummy.next
			dummy.next = head
			head = next
		return dummy.next

	def reverseList1(self, head):
		return self.doReverse(head, None)
	def doReverse(self, head, newHead):
		if head is None:
			return newHead
		next = head.next
		head.next = newHead
		return self.doReverse(next, head)




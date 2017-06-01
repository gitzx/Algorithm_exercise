'''
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def removeElements(self, head, val):
		dummy = ListNode(0)
		dummy.next = head
		cur = dummy
		while cur and cur.next:
			if cur.next.val == val:
				cur.next = cur.next.next
			else:
				cur = cur.next
		return dummy.next



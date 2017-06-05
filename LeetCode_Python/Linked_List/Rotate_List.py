'''
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def rotateRight(self, head, k):
		if k == 0 or head == None:
			return head
		dummy = ListNode(0)
		dummy.next = head
		tempNode = dummy
		count = 0
		while tempNode.next:
			tempNode = tempNode.next
			count += 1
		tempNode.next = dummy.next
		step = count - (k % count)
		for i in range(0, step):
			tempNode = tempNode.next
		head = tempNode.next
		tempNode.next = None
		return head
		
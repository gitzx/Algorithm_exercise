'''
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def deleteDuplicate(self, head):
		if head == None or head.next == None:
			return head
		dummy = ListNode(0)
		dummy.next = head
		p = dummy
		tmp = dummy.next
		while p.next:
			while tmp.next and tmp.next.val == p.next.val:
				tmp = tmp.next
			if tmp == p.next:
				p = p.next
				tmp = p.next
			else:
				p.next = tmp.next
		return dummy.next


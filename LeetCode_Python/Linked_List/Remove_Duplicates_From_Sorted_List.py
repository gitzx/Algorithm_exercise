'''
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solutiion(object):
	def deleteDuplicates(self, head):
		if head == None or head.next == None:
			return head
		p = head
		while p.next:
			if p.val == p.next.val:
				p.next = p.next.next
			else:
				p = p.next
		return head


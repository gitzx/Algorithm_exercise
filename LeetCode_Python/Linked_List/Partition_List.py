'''
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Soution(object):
	def partition(self, head, x):
		p1 = ListNode(0)
		p2 = ListNode(0)
		p = head
		newHead1 = p1
		newHead2 = p2
		while p:
			if p.val < x:
				p1.next = p
				p = p.next
				p1 = p1.next
				p1.next = None
			else:
				p2.next = p
				p = p.next
				p2 = p2.next
				p2.next = None
			
		p1.next = newHead2.next
		return newHead1.next


'''
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def reverseBetween(self, head, m, n):
		if head == None or head.next == None:
			return head
		dummy = ListNode(0)
		p = dummy
		q = head
		for i in range(m-1):
			p.next = q
			q = q.next
			p = p.next

		start = None
		end = q
		next = None
		for i in range(m, n+1):
			next = q.next
			q.next = start
			start = q
			q = next
		p.next = start
		end.next = next
		return dummy.next

		

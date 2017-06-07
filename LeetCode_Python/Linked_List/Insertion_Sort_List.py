'''
Sort a linked list using insertion sort.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def insertionSortList(self, head):
		if head is None:
			return head
		dummy = ListNode(0)
		dummy.next = head
		cur = head
		while cur.next:
			if cur.next.val < cur.val:
				pre = dummy
				while pre.next.val < cur.next.val:
					pre = pre.next
				tmp = cur.next
				cur.next = tmp.next
				tmp.next = pre.next
				pre.next = tmp
			else:
				cur = cur.next
		return dummy.next


'''
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def detectCycle(self, head):
		if head is None or head.next is None:
			return None
		slow = head.next
		fast = head.next.next
		while fast and fast.next and slow != fast:
			fast = fast.next.next
			slow = slow.next
		if fast is None or fast.next is None:
			return None
		slow = head
		while slow != fast:
			slow = slow.next
			fast = fast.next
		return slow
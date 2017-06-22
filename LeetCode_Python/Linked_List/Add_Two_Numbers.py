'''
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
'''

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		head = ListNode(0)
		l = head
		carry = 0
		while l1 or l2 or carry:
			sum, carry = carry, 0
			if l1:
				sum += l1.val
				l1 = l1.next
			if l2:
				sum += l2.val
				l2 = l2.next
			if sum > 9:
				carry = 1
				sum -= 10
			l.next = ListNode(sum)
			l = l.next
		return head.next


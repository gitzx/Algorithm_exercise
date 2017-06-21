'''
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

'''

'''
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

'''

class Solution(object):
	def sortedArrayToBST(self, array):
		length = len(array)
		if length == 0:
			return None
		if length == 1:
			return TreeNode(array[0])
		root = TreeNode(array[length/2])
		root.left = self.sortedArrayToBST(array[:length/2])
		root.right = self.sortedArrayToBST(array[length/2+1:])
		return root

	def sortedListToBST(self, head):
		array = []
		p = head
		while p:
			array.append(p.val)
			p = p.next
		return self.sortedArrayToBST(array)



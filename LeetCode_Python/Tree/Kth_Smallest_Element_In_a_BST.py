'''
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:

What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def kthSmallest(self, root, k):
		self.count = 0
		self.res = 0
		def inorder(root, k):
			if root == None or self.count >= k:
				return
			inorder(root.left, k)
			self.count += 1
			if self.count == k:
				self.res = root.val
			inorder(root.right, k)
		inorder(root, k)
		return self.res

		

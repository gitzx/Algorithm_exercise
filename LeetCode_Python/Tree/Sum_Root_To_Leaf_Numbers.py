'''
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def sumNumbers(self, root):
		def dfs(root, val):
			if root == None:
				return 0
			val = val * 10 + root.val
			if root.left == None and root.right == None:
				return val
			return dfs(root.left, val) + dfs(root.right, val)
			
		return dfs(root, 0)

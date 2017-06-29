'''
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	#dfs
	def dfs(self, root, isLeft):
		if root == None:
			return 0
		if root.left == None and root.right == None and isLeft:
			return root.val
		return self.dfs(root.left, True) + self.dfs(root.right, False)

	def sumOfLeftLeaves(self, root):
		return self.dfs(root, False)


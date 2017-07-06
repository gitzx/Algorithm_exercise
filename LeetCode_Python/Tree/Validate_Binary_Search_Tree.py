'''
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Binary tree [2,1,3], return true.

Example 2:

    1
   / \
  2   3

Binary tree [1,2,3], return false.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def isValidBST(self, root):
		INT_MAX = 4294967296
		INT_MIN = -4294967296
		def dfs(root, min, max):
			if root == None:
				return True 
			if root.val <= min or root.val >= max:
				return False 
			return dfs(root.left, min, root.val) and dfs(root.right, root.val, max)
		return dfs(root, INT_MIN, INT_MAX)

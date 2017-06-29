'''
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1

'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	#recursion
	def invertTree(self, root):
		if root is None:
			return None
		if root.left:
			self.invertTree(root.left)
		if root.right:
			self.invertTree(root.right)
		root.left, root.right = root.right, root.left
		return root




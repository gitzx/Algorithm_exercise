'''
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	#DFS
	def minDepth(self, root):
		if root is None:
			return 0
		left = self.minDepth(root.left)
		right = self.minDepth(root.right)
		if left and right:
			return min(left, right) + 1
		return max(left, right) + 1

	#BFS
	
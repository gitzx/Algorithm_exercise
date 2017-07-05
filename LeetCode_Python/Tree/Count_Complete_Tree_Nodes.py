'''
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:

In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def countNodes(self, root):
		if root == None:
			return 0
		hl = hr = 0
		l = root
		r = root
		while l:
			hl += 1
			l = l.left
		while r:
			hr += 1
			r = r.right
		if hl == hr:
			return pow(2, hl) - 1
		return 1 + self.countNodes(root.left) + self.countNodes(root.right)


'''
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def inorderTraversal_recursion(self, root, list):
		if root:
			self.inorderTraversal_recursion(root.left, list)
			list.append(root.val)
			self.inorderTraversal_recursion(root.right, list)

	def inorderTraversal_iteration(self, root, list):
		stack = []
		while root or stack:
			if root:
				stack.append(root)
				root = root.left
			else:
				root = stack.pop()
				list.append(root.val)
				root = root.right
		return list

	def inorderTraversal(self, root):	
		list = []
		self.inorderTraversal_iteration(root, list)
		return list

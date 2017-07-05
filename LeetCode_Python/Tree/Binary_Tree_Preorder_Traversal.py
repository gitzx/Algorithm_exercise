'''
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
	def preorder_recursion(self, root, list):
		if root:
			list.append(root.val)
			self.preorder_recursion(root.left, list)
			self.preorder_recursion(root.right, list)

	#iteration
	def preorder(self, root, list):
		stack = []
		while root or stack:
			if root:
				list.append(root.val)
				stack.append(root)
				root = root.left
			else:
				root = stack.pop()
				root = root.right
		return list

	def preorderTraversal(self, root):
		list = []
		self.preorder_recursion(root, list)
		return list

		
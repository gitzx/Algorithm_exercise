'''
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def buildTree(self, inorder, postorder):
		if not inorder:
			return None
		root = TreeNode(postorder[-1])
		rootPos = inorder.index(postorder[-1])
		root.left = self.buildTree(inorder[:rootPos], postorder[:rootPos])
		root.right = self.buildTree(inorder[rootPos + 1: ], postorder[rootPos : -1])
		return root





'''
Given preorder and inorder traversal of a tree, construct the binary tree.

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
	def buildTree(self, preorder, inorder):
		if not inorder:
			return None
		root = TreeNode(preorder[0])
		rootPos = inorder.index(preorder[0])
		root.left = self.buildTree(preorder[1 : 1+ rootPos], inorder[: rootPos])
		root.right = self.buildTree(preorder[rootPos + 1: ], inorder[rootPos + 1: ])
		return root

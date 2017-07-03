'''
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def dfs(self, start, end):
		if start > end:
			return [None]
		res = []
		for root_val in range(start, end + 1):
			leftTree = self.dfs(start, root_val-1)
			rightTree = self.dfs(root_val + 1, end)
			for i in leftTree:
				for j in rightTree:
					root = TreeNode(root_val)
					root.left = i
					root.right = j
					res.append(root)
		return res

	def generateTrees(self, n):
		if n == 0:
			return []
		return self.dfs(1, n)

		


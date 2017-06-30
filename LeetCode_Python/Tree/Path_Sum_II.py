'''
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def pathSum(self, root, sum):
		res = []
		if root == None:
			return []
		def dfs(root, curSum, valueList):
			if root.left == None and root.right == None and curSum == sum:
				res.append(valueList)
			if root.left:
				dfs(root.left, curSum+root.left.val, valueList+[root.left.val])
			if root.right:
				dfs(root.right, curSum+root.right.val, valueList+[root.right.val])
		dfs(root, root.val, [root.val])
		return res

		
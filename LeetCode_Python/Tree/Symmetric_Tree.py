'''
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def dfs(self, p, q):
		if p == None and q == None:
			return True
		if p and q and p.val == q.val:
			return self.dfs(p.right, q.left) and self.dfs(p.left, q.right)
		return False
	def isSymmetric(self, root):
		if root:
			return self.dfs(root.left, root.right)
		return True

		
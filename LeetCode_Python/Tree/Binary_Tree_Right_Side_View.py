'''
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4].
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def rightSideView(self, root):
		ans = []
		if root is None:
			return ans
		queue = [root]
		while queue:
			size = len(queue)
			for r in range(size):
				top = queue.pop(0)
				if r == 0:
					ans.append(top.val)
				if top.right:
					queue.append(top.right)
				if top.left:
					queue.append(top.left)
		return ans



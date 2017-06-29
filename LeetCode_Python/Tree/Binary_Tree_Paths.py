'''
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
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
	def binaryTreePaths(self, root):
		self.result = []
        if root is None:
            return self.result
        def dfs(root, path):
            if root.left is None and root.right is None:
                self.result += path,
            if root.left:
                dfs(root.left, path + "->" + str(root.left.val))
            if root.right:
                dfs(root.right, path + "->" + str(root.right.val))
        dfs(root, str(root.val))
        return self.result

    #BFS
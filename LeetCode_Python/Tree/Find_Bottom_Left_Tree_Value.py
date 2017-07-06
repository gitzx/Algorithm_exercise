'''
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1

Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	#dfs
	def findBottomLeftValue(self, root):
		val = 0
		maxDepth = 0
		def dfs(root, depth):
			if root == None:
				return
			if depth > maxDepth:
				maxDepth = depth
				val = root.val
			if root.left:
				dfs(root.left, depth + 1)
			if root.right:
				dfs(root.right, depth + 1)
		dfs(root, 1)
		return val

	def findBottomLeftValue2(self, root):
		from Queue import Queue
        queue = Queue()
        queue.put(root)
        node = None
        while not queue.empty():
            node = queue.get()
            if node.right:
                queue.put(node.right)
            if node.left:
                queue.put(node.left)

        return node.val

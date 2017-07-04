'''
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree,
each node's right child points to the next node of a pre-order traversal.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def flatten(self, root):
		self.pointer = None
		def traverse(root):
			if not root:
				return
			traverse(root.right)
			traverse(root.left)
			root.right = self.pointer
			root.left = None
			self.pointer = root
		traverse(root)

	def flatten2(self, root):
		pointer = TreeNode(None)
		stack = [root]
		while stack:
			top = stack.pop()
			if not top:
				continue
			stack.append(top.right)
			stack.append(top.left)
			pointer.right = top
			pointer.left = None
			pointer = top



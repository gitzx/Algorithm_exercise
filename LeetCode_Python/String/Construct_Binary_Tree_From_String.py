'''
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. 
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:

Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   

Note:

There will only be '(', ')', '-' and '0' ~ '9' in the input string.
'''

'''
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
'''

class Solution(object):
	def str2tree(self, t):
		if not s:
			return None
		n = ''
		while s and s[0] not in ('(', ')'):
			n += s[0]
			s = s[1:]
		node = TreeNode(int(n))
		left, right = self.divide(s)
		node.left = self.str2tree(left[1:-1])
		node.right = self.str2tree(right[1:-1])
		return node
		
	def divide(self, s):
		part, count = '', 0
		while s:
			count += {'(':1, ')':-1}.get(s[0], 0)
			part += s[0]
			s = s[1:]
			if count == 0:
				break
		return part, s











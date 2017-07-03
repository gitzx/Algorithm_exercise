'''
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

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
	def numTrees(self, n)	
		dp = [1, 1, 2]
		if n <= 2:
			return dp[n]
		else:
			dp += [0 for i in range(n-2)]
			for i in range(3, n+1):
				for j in range(0, i):
					dp[i] += dp[j]*dp[i-j-1]
			return dp[n]

''' # time exceeded
	def numTrees2(self, n):
		if n == 0 or n == 1:
			return 1
		elif n == 2:
			return 2
		else:
			result = 0
			for i in range(0, n):
				result += self.numTrees(i)*self.numTrees(n-i-1)
			return result	
'''
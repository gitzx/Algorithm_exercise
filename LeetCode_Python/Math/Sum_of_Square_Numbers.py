'''
Given a non-negative integer c, 
your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True

Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False
'''

class Solution(object):
	def judgeSquareSum(self, c):
		for a in range(int(c**0.5) + 1):
			b = c - a ** 2
			if (int(b ** 0.5)) ** 2 == b:
				return  True
		return False
		
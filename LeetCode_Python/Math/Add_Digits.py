'''
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:

Could you do it without any loop/recursion in O(1) runtime?
'''

class Solution(object):
	def addDigits(self, num):
		while num > 9:
			c = 0
			while num:
				c += num % 10
				num /= 10
			num = c
		return num

	def addDigits2(self, num):
		if num == 0:
			return 0
		return (num - 1) % 9 + 1	
		
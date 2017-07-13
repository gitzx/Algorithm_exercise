'''
Given an integer, write a function to determine if it is a power of three.

Follow up:

Could you do it without using any loop / recursion?
'''

class Solution(object):
	#recursion
	def isPowerOfThree(self, n):
		if n == 1:
			return True
		if n == 0 or n % 3 > 0:
			return False
		return self.isPowerOfThree(n / 3)

	def isPowerOfThree2(self, n):
		return n > 0 and 3 ** round(math.log(n, 3)) == n

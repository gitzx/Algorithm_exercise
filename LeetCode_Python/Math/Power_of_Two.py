'''
Given an integer, write a function to determine if it is a power of two.
'''

class Solution(object):
	#如果一个整数是2的幂，那么它的二进制形式最高位为1，其余各位为0
	def isPowerOfTwo(self, n):
		return n > 0 and n & (n - 1) == 0
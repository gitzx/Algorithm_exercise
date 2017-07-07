'''
Implement int sqrt(int x).

Compute and return the square root of x.
'''

class Solution(object):
	def mySqrt(self, x):
		low, high, mid = 0, x, x/2
		while low <= high:
			if mid * mid > x:
				high = mid -1
			else:
				low = mid + 1
			mid = (low + high)/2
		return mid

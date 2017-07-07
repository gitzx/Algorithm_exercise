'''
Given an integer array, 
find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6

Example 2:

Input: [1,2,3,4]
Output: 24

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
'''

class Solution(object):
	def maximumProduct(self, nums):
		ans = None
		maxa = maxb = maxc = None
		mina = minb = 0x7FFFFFFF
		for n in nums:
			if n > maxa: 
				maxa, maxb, maxc = n, maxa, maxb
			elif n > maxb:
				maxb, maxc = n, maxb
			elif n > maxc:
				maxc = n
			if n < mina:
				mina, minb = n, mina
			elif n < minb:
				minb = n
		return max(ans, maxa * mina * minb, maxa * maxb * maxc)
		
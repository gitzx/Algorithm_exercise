'''
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:

Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory? 
'''

class Solution(object):
	def singleNumber(self, nums):
		ans = 0
		for num in nums:
			ans ^= num
		return ans

	def singleNumber2(self, nums):
		return reduce(operator.xor, nums)

	def singleNumber3(self, nums):
		return reduce(lambda x, y: x^y, nums)
		

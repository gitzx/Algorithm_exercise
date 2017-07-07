'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:

Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant extra space complexity?
'''

class Solution(object):
	def missingNumber(self, nums):
		sum = 0
		count = 0
		for i in nums:
			sum += i
			count += 1
		return count*(count + 1)/2 - sum

	def missingNumber2(self, nums):
		a = reduce(operator.xor, nums)
		b = reduce(operator.xor, range(len(nums) + 1))
		return a ^ b
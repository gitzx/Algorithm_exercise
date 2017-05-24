'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

'''

import operator

class Solution(object):
	def missingNumber(self, nums):
		return (len(nums) * (len(nums) + 1))/2 - sum(nums)

	def missingNumber2(self, nums):
		n1 = reduce(operator.xor, nums)
		n2 = reduce(operator.xor, range(len(nums) + 1))
		return n1 ^ n2

if __name__ == '__main__':
	nums = [0, 1, 3]
	result = Solution().missingNumber2(nums)
	print result


# -*- coding: utf-8 -*-

'''
Given an integer array of size n, 
find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

'''

class Solution(object):
	def majorityElement(self, nums):
		n1 = n2 = None
		c1 = c2 = 0
		for num in nums:
			if n1 == num:
				c1 += 1
			elif n2 == num:
				c2 += 1
			elif c1 == 0:
				n1, c1 = num, 1
			elif c2 == 0:
				n2, c2 = num, 1
			else:
				c1, c2 = c1 - 1, c2 - 1
		size = len(nums)
		return [n for n in (n1, n2)
			if n is not None and nums.count(n) > size / 3]

if __name__ == '__main__':
	nums = [1,2,3,1,1,2,2]
	result = Solution().majorityElement(nums)
	print result  # [1, 2]
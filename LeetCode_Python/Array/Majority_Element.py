# -*- coding: utf-8 -*

'''
Given an array of size n, find the majority element. 

The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

'''

import math
class Solution(object):
	def majorityElement(self, nums):
		hash = {}
		for n in nums:
			if n not in hash.keys():
				hash[n] = 1
			else:
				temp = hash[n]
				hash[n] = temp + 1
		maximum = 0
		majority = nums[0]
		for i in hash:
			if hash[i] > maximum:
				maximum = hash[i]
				majority = i

		assert maximum > math.floor(len(nums)/2.0)
		return majority 

	# Moore投票算法
	def majorityElement2(self, nums):
		candicate, count = None, 0
		for n in nums:
			if count == 0:
				candicate, count = n, 1
			elif n == candicate:
				count += 1
			else:
				count -= 1
		return candicate

if __name__ == '__main__':
	nums = [1,2,1,1,3]
	result = Solution().majorityElement(nums)
	print result # 1
# -*- coding: utf-8 -*

'''
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]

'''

class Solution(object):
	def findAllDuplicatesInAnArray(self, nums):
		result = []
		for n in nums:
			if nums[abs(n) - 1] < 0:
				result.append(abs(n))
			else:
				nums[abs(n) - 1] *= -1
		return result

	def findAllDuplicatesInAnArray2(self, nums):
		result = []
		for i in range(len(nums)):
			while nums[i] and nums[i] != i+1:
				n = nums[i]
				if nums[i] == nums[n-1]:
					result.append(n)
					nums[i] = 0
				else:
					nums[i], nums[n-1] = nums[n-1], nums[i]
		return result

if __name__ == '__main__':
	nums = [4,3,2,7,8,2,3,1]
	result = Solution().findAllDuplicatesInAnArray(nums)
	print result  #[2, 3]




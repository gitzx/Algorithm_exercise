# -*- coding: utf-8 -*

'''
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

'''

class Solution(object):
	#正负号标记法 类似：Find_All_Duplicates_In_An_Array.py
	def findAllNumbersDisappearedInAnArray(self, nums):
		for n in nums:
			nums[abs(n)-1] = -abs(nums[abs(n)-1])
		return [i+1 for i, n in enumerate(nums) if n > 0]

if __name__ == '__main__':
	nums = [4,3,2,7,8,2,3,1]
	result = Solution().findAllNumbersDisappearedInAnArray(nums)
	print result














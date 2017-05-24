# -*- coding:utf8 -*- 
'''
Given a sorted array and a target value, return the index if the target is found. If not, 
return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

'''

class Solution(object):
	def searchInsert(self, nums, target):
		left, right= 0, len(nums) - 1
		while left <= right:
			mid = (left + right)/2
			if target == nums[mid]:
				return mid
			elif target < nums[mid]:
				if mid -1 < left or target > nums[mid -1]:
					return mid
				right = mid - 1
			else:
				if mid + 1 > right or target < nums[mid+1]:
					return mid + 1
				left = mid + 1

if __name__ == '__main__':
	nums = [1,3,5,6]
	result = Solution().searchInsert(nums, 0)
	print result  # 0 

